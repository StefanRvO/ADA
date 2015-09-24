#include <list>

class Node
{
  private:
    int value;
    std::list<Node *> sub_nodes;
  public:
    Node(int _value);

    ~Node();
    void add_subnode(int value);
    void add_subnode(Node &x);
    void setValue(int _value);
    int getValue();
};
