/*
 * Name: GIACONE, JORDAN
 * Class and Section: CS153, Section C
 * Date: 4-17-14
 */

template <typename T>
const LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& rhs)
{
  if(this != &rhs)
  {
    LinkedList<T>* p = this;
    int size = rhs.size();
    clear();

    const LinkedList<T>* ptr = &rhs;

    for(int i = 0; i < size; i++)
    {
      p->m_data = ptr->m_data;
      ptr = ptr->m_next;
      p->m_next = new LinkedList<T>;
      p = p->m_next;
    }
  }

  return *this;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
  m_next = new LinkedList<T>();

  *this = rhs;
}

template <typename T>
int LinkedList<T>::size() const
{
  //If we've hit the sentinel node
  if(m_next == NULL)
  {
    return 0;
  }

  return m_next->size() + 1;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  return m_next == NULL;
}

template <typename T>
LinkedList<T>* LinkedList<T>::getFirstPtr()
{
  if(m_next == NULL)
  {
      std::cout << "Panic in LinkedList.getFirstPtr()! Empty List!" << std::endl;
      return NULL;
  }

  return this;
}

template <typename T>
LinkedList<T>* LinkedList<T>::getLastPtr()
{
  if(m_next != NULL && m_next -> m_next == NULL)
  {
    return this;
  }
  else if(m_next == NULL)
  {
      std::cout << "Panic in LinkedList.getLastPtr()! Empty List!" << std::endl;
      return NULL;
  }

  return m_next -> getLastPtr();
}

template <typename T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i)
{
  int size = this->size();

  if(i >= size || i < 0)
  {
    std::cout << "Panic in LinkedList.getAtPtr(). " << i << " is an invalid index!" << std::endl;
    return NULL;
  }

  LinkedList<T>* p = this;

  for(int j = 0; j < i; j++)
  {
    p = p -> m_next;
  }

  return p;
}

template <typename T>
void LinkedList<T>::clear()
{
  if(m_next != NULL)
  {
    m_next -> clear();

    delete m_next;
    m_next = NULL;
  }
}

template <typename T>
void LinkedList<T>::insert_front(const T& x)
{
  insert(x, this);
}

template <typename T>
void LinkedList<T>::insert(const T& x, LinkedList<T>* pos)
{
  LinkedList<T>* p = new LinkedList<T>;

  p->m_data = pos->m_data;
  pos->m_data = x;
  p->m_next = pos->m_next;
  pos->m_next = p;

  p = NULL;
}

template <typename T>
void LinkedList<T>::remove(LinkedList<T>* pos)
{
  LinkedList<T>* p = getFirstPtr();

  while(p->m_next != NULL && p->m_next != pos)
  {
    p = p->m_next;
  }

  p->m_next = pos->m_next;
  pos->m_next = NULL;
  delete pos;
  pos = NULL;
}

template <typename T>
bool LinkedList<T>::operator == (const LinkedList<T>& rhs) const
{
  const LinkedList<T>* a = this;
  const LinkedList<T>* b = &rhs;

  while((a -> m_next != NULL && a -> m_next -> m_next != NULL) &&
        (b -> m_next != NULL && b -> m_next -> m_next != NULL))
  {
    if(a -> m_data != b -> m_data)
    {
      return false;
    }

    a = a->m_next;
    b = b->m_next;
  }

  return true;
}

template <typename T>
LinkedList<T>* LinkedList<T>::find(const T& x)
{
  LinkedList<T>* p = this;

  while(p->m_data != x && p->m_next != NULL)
  {
    p = p->m_next;
  }

  return p;
}

template <typename T>
void LinkedList<T>::reverse()
{
  LinkedList<T>* temp = new LinkedList<T>;
  LinkedList<T>* p = this;

  while(p->m_next != NULL)
  {
      temp->insert_front(p->m_data);//(*temp).insert_front((*p).m_data);
      p = p->m_next;
  }

  *this = *temp;
  temp->clear();
  delete temp;
}

template <typename T>
void LinkedList<T>::append(const LinkedList<T> & xlist)
{
  LinkedList<T>* p = getLastPtr();
  const LinkedList<T>* ptr = &xlist;

  delete p->m_next;
  p->m_next = new LinkedList<T>;
  p = p->m_next;

  while(ptr->m_next != NULL)
  {
    p->m_next = new LinkedList<T>;
    p->m_data = ptr->m_data;
    ptr = ptr->m_next;
    p = p->m_next;
  }
}
