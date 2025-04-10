#include <chrono>
#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

#include <engine/core/application.hpp>
#include <engine/gameplay/sceneManager.hpp>

namespace LOLCore{
    Application::Application(){}
    Application::~Application(){}
    int Application::Execute(){
        if(!Init()){
            spdlog::info("Application is not inited");
            return EXIT_FAILURE;
        }

        Loop();

        return EXIT_SUCCESS;
    }

    // private: // methods
    bool Application::Init(){
        if(!ValidateAppSettings())
            return false;
        if(!InitWindow())
            return false;

        InitSceneManager();
        
        Loop();

        CleanUp();
        return true;
    }

    void Application::Loop(){
        using clock = std::chrono::high_resolution_clock;
        using duration = std::chrono::duration<double>;

        auto lastUpdateTime = clock::now();
        auto lastFrameTime = lastUpdateTime;

        auto windowSettings = _gameApp.GetWindowSettings();

        std::optional<duration> frameTimeLimit;
        if(windowSettings.frameLmit > 0)
            frameTimeLimit = duration(1.0 / static_cast<double>(windowSettings.frameLmit));

        StartFixedUpdateThread();

        while(!glfwWindowShouldClose(_window.get())){
            auto now = clock::now();
            auto deltaTime = now - lastUpdateTime;
            
            glfwPollEvents();

            Update(deltaTime.count());
            PostUpdate(deltaTime.count());
            if(!frameTimeLimit.has_value() || ((now - lastFrameTime) >= frameTimeLimit.value())){
                Draw();
                glfwSwapBuffers(_window.get());
                lastFrameTime = now;
            }

            lastUpdateTime = now;
        }

        StopFixedUpdateThread();
    }

    void Application::StartFixedUpdateThread(){
        auto appSettings = _gameApp.GetWindowSettings();
        if(appSettings.fixedUpdateFrequency == 0){
            spdlog::warn("Fixed update frequency is 0. FixedUpdate is disabled");
            return;
        }
        _fixedUpdateTime.store(1.0/static_cast<double>(appSettings.fixedUpdateFrequency));
        _isRunning.store(true);
        _fixedUpdateThread = std::thread([this](){
            using clock = std::chrono::high_resolution_clock;
            using duration = std::chrono::duration<double>;

            auto nextFrame = clock::now();
            double accumulator {0.0};

            while (_isRunning.load(std::memory_order_relaxed)){   
                double fixedUpdateTime = _fixedUpdateTime.load(std::memory_order_relaxed);
                if(fixedUpdateTime == 0.0)
                    break;

                auto frameStart = clock::now();
                auto frameTime = duration(frameStart - nextFrame).count();
                accumulator += frameTime;
                while (accumulator >= fixedUpdateTime){
                    _fixedUpdateMutex.lock();
                    FixedUpdate(fixedUpdateTime);
                    _fixedUpdateMutex.unlock();
                    accumulator  -= fixedUpdateTime;
                }
                nextFrame += std::chrono::duration_cast<clock::duration>(duration(fixedUpdateTime));
                std::this_thread::sleep_until(nextFrame);
            }
        });
    }

    void Application::StopFixedUpdateThread(){
        _isRunning.store(false);
        _fixedUpdateThread.join();
    }

    bool Application::InitWindow(){
        if(GLFW_TRUE != glfwInit()){
            spdlog::error("Failed to init GLFW");
            return false;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        auto windowSettings = _gameApp.GetWindowSettings();
        _window.reset(glfwCreateWindow(windowSettings.screenWidth, windowSettings.screenHeight, windowSettings.appName.c_str(), nullptr, nullptr));
        if(!_window){
            spdlog::error("Window is not created");
            return false;
        }

        glfwMakeContextCurrent(_window.get());

        return true;
    }

    void Application::InitSceneManager(){
        _sceneManager = std::make_unique<LOLGameplay::SceneManager>();
        _gameApp.RegisterScenes([this](std::string_view sceneName, LOLGameplay::SceneCreateCallbackT factoryCallback){
            _sceneManager->RegisterScene(sceneName, factoryCallback);
        });
        _sceneManager->SetCurrentScene(_gameApp.GetStartSceneName());
    }

    bool Application::ValidateAppSettings(){
        auto windowSettings = _gameApp.GetWindowSettings();
        if(windowSettings.screenWidth == 0 || windowSettings.screenHeight == 0){
            spdlog::error("Screen size can't be 0");
            return false;
        }

        return true;
    }

    void Application::CleanUp(){
    }

    void Application::FixedUpdate(const double fixedDeltaTime){
        //@todo physics fixed update
    }

    void Application::Update(const double frameDeltaTime){
        _sceneManager->Update(frameDeltaTime);
    }

    void Application::PostUpdate(const double frameDeltaTime){
        _sceneManager->PostUpdate(frameDeltaTime);
    }


    // void Application::Update(const float deltaFrame){
    //     _sceneManager->Update(deltaFrame);
    // }

    void Application::Draw() const{
        _sceneManager->Draw();
    }
} // namespace LOLCore
