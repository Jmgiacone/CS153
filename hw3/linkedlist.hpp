template <typename T>
const LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& rhs)
{
  /*if(this != &rhs)
  {
    int size = rhs.size();
    clear();
    
    LinkedList<T>* p = rhs.getFirstPtr();

    for(int i = 0; i < size; i++)
    {
      insert(p->m_data, getAtPtr(i));
      p = p->m_next;
    }
  }*/

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
      return NULL;
  }

  return this;
}

template <typename T>
LinkedList<T>* LinkedList<T>::getLastPtr()
{
  if(m_next != NULL && m_next -> m_next == NULL)
  {
    return m_next;
  }
  
  return m_next -> getLastPtr();
}

template <typename T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i)
{
  LinkedList* p = this;

  for(int j = 0; j < i && p -> m_next != NULL && p -> m_next -> m_next != NULL; j++)
  {
    p = p -> m_next;
  }

  return p;
}

template <typename T>
void LinkedList<T>::clear()
{
  if(m_next != NULL && m_next -> m_next != NULL)
  {
    m_next -> clear();  
   
    delete m_next -> m_next;
    m_next = NULL; 
  }
}

template <typename T>
void LinkedList<T>::insert_front(const T& x)
{
  LinkedList<T>* p;

  if(m_next == NULL)
  {
    p = new LinkedList<T>;
    p->m_next = this;
    p->m_data = x;
  }
  else
  {
    p->m_data = x;
    p->m_next = this;
    m_next = p;
  }

  p = NULL;
}

template <typename T>
void LinkedList<T>::insert(const T& x, LinkedList<T>* pos)
{
  LinkedList<T>* p = new LinkedList<T>;

  p->m_data = x;
  p->m_next = pos->m_next;
  pos->m_next = p;

  p = NULL;
}

template <typename T>
void LinkedList<T>::remove(LinkedList<T>* pos)
{
  LinkedList<T>* p = getFirstPtr();

  while(p->m_next != this)
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
  /*LinkedList<T>* a = this;
  LinkedList<T>* b = &rhs;

  while((a -> m_next != NULL && a -> m_next -> m_next != NULL) && 
        (b -> m_next != NULL && b -> m_next -> m_next != NULL))
  {
    if(a -> m_data != b -> m_data)
    {
      return false;
    }

    a = a -> m_data;
    b = b -> m_data;
  }*/

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

}

template <typename T>
void LinkedList<T>::append(const LinkedList<T> & xlist)
{
  /*LinkedList<T>* p = getLastPtr();

  delete p -> m_next;
  p -> m_next = xlist.getFirstPtr();*/
}
