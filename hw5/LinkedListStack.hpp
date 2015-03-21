/*
 * Name: GIACONE, JORDAN
 * Class and Section: CS153, Section C
 * Date: 4-17-14
 */

template <typename T>
void LinkedListStack<T>::clear()
{
  if(size != 0)
  {
    next -> clear();
  }
  size = 0;
}

template <typename T>
bool LinkedListStack<T>::isEmpty() const
{
  return size == 0;
}

template <typename T>
void LinkedListStack<T>::pop()
{
  if(size > 1)
  {
    LinkedList<T>* p = next;
    next = p->m_next;
    delete p;
    p = NULL;
  }
  else if(size == 1)
  {
    delete next;
    next = NULL;
  }
  size--;
}

template <typename T>
void LinkedListStack<T>::push(const T& x)
{
  if(next == NULL)
  {
    next = new LinkedList<T>;
    next->m_data = x;
  }
  else
  {
      LinkedList<T>* p = new LinkedList<T>;
      p->m_data = x;
      p->m_next = next;
      next = p;
      p = NULL;
  }
  size++;
}

template <typename T>
const T& LinkedListStack<T>::top() const throw (Oops)
{
  if(size != 0)
  {
      return next -> m_data;
  }
  throw new Oops("You can't see the top of an empty Stack!");
}

template <typename T>
LinkedListStack<T>::~LinkedListStack()
{
  if(next != NULL)
  {
    next -> clear();
  }
}
