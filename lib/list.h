#ifndef list_h
#define list_h

struct list_node;

class list {
private:
  list_node *head, *tail;
public:
  list();
  int length;
  void push(int *);
  void pop();
  void clear();
  int *get(int) const;
};

#endif
