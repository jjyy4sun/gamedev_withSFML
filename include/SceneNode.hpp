#pragma once
#include<vector>
#include <SFML/Graphics.hpp>

class SceneNode : public sf::Transormable, public sf::Drawable,
                  private sf::NonCopyable {
  public:
    typedef std::unique_ptr<SceneNode> ScenePtr;

  public:
    SceneNode();
    void attachChild(ScenePtr child);
    ScenePtr detachChild(const SceneNode& node);
    void update(sf::Time dt);
    sf::Vector2f getWorldPosition() const;
  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);
    void updateChildren(sf::Time dt);
    sf::Transform getWorldTransform() const;

  private:
    std::vector<ScenePtr> mChildren;
    SceneNode* mParent;
};