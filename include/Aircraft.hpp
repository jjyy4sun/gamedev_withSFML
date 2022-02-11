#include"Entity.hpp"
class Aircraft : public Entity {
  public:
    enum Type {
        Enagle,
        Raptor
    };

    explicit Aircraft(Type type);

  private:
    Type mType;
}