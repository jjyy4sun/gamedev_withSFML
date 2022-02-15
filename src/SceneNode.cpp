#include"SceneNode.hpp"

void SceneNode::attachChild(ScenePtr child) {
    child->mParent = this;
    mChildren.push_back(std::move(child));
}


SceneNode::ScenePtr SceneNode::detachChild(const SceneNode& node) {
    auto found = std::find_if(mChildren.begin(), mChildren.end(),
    [&] (ScenePtr& p) -> bool { return p.get() == &node; });

    assert(found != mChildren.end());

    ScenePtr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;
}

SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    drawCurrent(target, states);

    for (const ScenePtr& child : mChildren) {
        child->draw(target, states);
    }
}

SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mSprite, states);
}