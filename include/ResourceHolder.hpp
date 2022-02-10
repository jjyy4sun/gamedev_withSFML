#include<map>
#include<cassert>

template<typename ResourceType, typename ID>
class ResourceHolder {
 public:
    void Load(ID resid, const std::string filename);
    template<typename ParamentType>
    void Load(ID resid, const std::string filename, const ParamentType& anotherparament);
    ResourceType& get(ID resid);
    const ResourceType& get(ID resid) const;
 private:

 private:
    std::map<ID,std::unique_ptr<ResourceType>> mResourceMap;
};

#include"ResourceHolder.inl"