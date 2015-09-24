#include "Node.hpp"

Node::Node(int _value)
{
  value = _value;
}

Node::~Node()
{
  for(auto &x : sub_nodes)
  {
    delete x;
  }
}

void Node::add_subnode(int value)
{
  sub_nodes.push_back(new Node(value));
}

void Node::add_subnode(Node &x)
{
  sub_nodes.push_back(&x);
}

void Node::setValue(int _value)
{
  value = _value;
}
int Node::getValue()
{
  return value;
}
