#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

#include <engine/core/application.hpp>

#include <engine/gameplay/sceneManager.hpp>

namespace LOLCore{
    Application::Application()
    : _appSettings(GetApplicationSettings()){}
    Application::~Application(){}

    int Application::Start(){
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
        double lastUpdateTime = glfwGetTime();
        double lastFrameTime = 0.0;

        std::optional<double> frameTimeLimit;
        if(_appSettings.frameLimit > 0)
            frameTimeLimit = 1.0 / static_cast<double>(_appSettings.frameLimit);

        while(!glfwWindowShouldClose(_window.get())){
            double now = glfwGetTime();
            double deltaTime = now - lastUpdateTime;
            
            glfwPollEvents();

            Update(deltaTime);
            if(!frameTimeLimit.has_value() || (now - lastFrameTime >= frameTimeLimit)){
                Draw();
                glfwSwapBuffers(_window.get());
                lastFrameTime = now;
            }

            lastUpdateTime = now;
        }
    }

    bool Application::InitWindow(){
        if(GLFW_TRUE != glfwInit()){
            spdlog::error("Failed to init GLFW");
            return false;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        _window.reset(glfwCreateWindow(_appSettings.screenWidth, _appSettings.screenHeight, _appSettings.appName.c_str(), nullptr, nullptr));
        if(!_window){
            spdlog::error("Window is not created");
            return false;
        }

        glfwMakeContextCurrent(_window.get());

        return true;
    }

    void Application::InitSceneManager(){
        _sceneManager = std::make_unique<LOLGameplay::SceneManager>();
        _sceneManager->SetCurrentScene(_appSettings.startScene);
    }

    bool Application::ValidateAppSettings(){
        if(_appSettings.screenWidth == 0 || _appSettings.screenHeight == 0){
            spdlog::error("Screen size can't be 0");
            return false;
        }
        if(_appSettings.startScene.empty()){
            spdlog::error("No start scene is set");
            return false;
        }

        return true;
    }

    void Application::CleanUp(){
    }

    void Application::Update(const float deltaFrame){
        _sceneManager->Update(deltaFrame);
    }

    void Application::Draw() const{
        _sceneManager->Draw();
    }
} // namespace LOLCore
