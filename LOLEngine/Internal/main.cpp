#include <Engine/Core/Application.hpp>

int main(){
    LOLCore::Application application;
    
    if(!application.Init()){
        application.Shutdown();
        return EXIT_FAILURE;
    }

    application.Loop();
    application.Shutdown();

    return EXIT_SUCCESS;
}