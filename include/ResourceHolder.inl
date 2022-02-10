
template<typename ResourceType, typename ID>
void ResourceHolder<ResourceType, ID>::Load(ID resid, const std::string filename) {
    std::unique_ptr<ResourceType> resource(new ResourceType);
    if (!resource->loadFromFile(filename)) {
        throw std::runtime_error("Resource::load Fail to load " + filename);
    }
    auto insert_status = mResourceMap.insert(std::make_pair(resid, std::move(resource)));
    assert(insert_status.second);
}

template<typename ResourceType, typename ID>
template<typename ParamentType>
void ResourceHolder<ResourceType, ID>::Load(ID resid, const std::string filename, const ParamentType& anotherparament) {
    std::unique_ptr<ResourceType> resource(new ResourceType);
    if (!resource->loadFromFile(filename, anotherparament)) {
        throw std::runtime_error("Resource::load Fail to load " + filename);
    }
    auto insert_status = mResourceMap.insert(std::make_pair(resid, std::move(resource)));
    assert(insert_status.second);
}

template<typename ResourceType, typename ID>
ResourceType& ResourceHolder<ResourceType, ID>::get(ID resid) {
    auto found = mResourceMap.find(resid);
    assert(found != mResourceMap.end()); 
    return *(found->second.get());
}

template<typename ResourceType, typename ID>
const ResourceType& ResourceHolder<ResourceType, ID>::get(ID resid) const {
    auto found = mResourceMap.find(resid);
    assert(found != mResourceMap.end());
    return *(found->second.get());
}