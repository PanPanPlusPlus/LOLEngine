#pragma once
#include <map>
#include <typeindex>
#include <memory>

namespace LOLCore{
    class ServiceProvider{
    public:
        ServiceProvider() = default;

        template<typename T>
        const bool HasService() const{
            return _services.end() != _services.find(typeid(T));
        }

        template<typename T>
        void RegisterService(std::shared_ptr<const T> service){
            _services[typeid(T)] = service;
        }

        template<typename T>
        std::shared_ptr<const T> const GetService() const{
            auto serviceIt = _services.find(typeid(T));
            if(_services.end() == serviceIt)
                return nullptr;
            
            return std::static_pointer_cast<const T>(serviceIt->second);
        }

    private: // properties
        std::map<std::type_index, std::shared_ptr<const void>> _services;
    }; // ServiceProvider
} // namespace LOLCore
