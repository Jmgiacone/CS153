/*
 * GIACONE, JORDAN	
 * 2-19-14
 * CS 153, Section C
 * This is the templated ArrayList class
 */

template <typename T>
ArrayList<T>::~ArrayList()
{
  m_max = 0;
  m_size = 0;

  delete [] m_data;
  m_data = NULL;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator = (const ArrayList<T>& rhs)
{
  if(this != &rhs)
  {
    delete [] m_data;
    m_max = rhs.m_max;
    m_size = rhs.m_size;
    m_data = new T[m_max];

    for(int i = 0; i < m_size; i++)
    {
      m_data[i] = rhs.m_data[i];
    }
  }
  return *this;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
  m_max = 0;
  m_size = 0;
  m_data = new T[1];
   
  *this = cpy;
}

template <typename T>
int ArrayList<T>::size() const
{
  return m_size;
}

template <typename T>
const T& ArrayList<T>::first() const
{
  if(m_size == 0)
  {
    std::cout << "!-- Error : PANIC in ARRAYLIST!!.first()!!" 
              << " (List is empty)" << std::endl;
    return m_errobj;
  }

  return m_data[0];
}

template <typename T>
const T& ArrayList<T>::operator [] (int i) const
{
  if(m_size == 0 || (i < 0 || i >= m_size))
  {
    return m_errobj;
  }

  return m_data[i];
}

template <typename T>
T& ArrayList<T>::operator [] (int i)
{
  if(m_size == 0 || (i < 0 || i >= m_size))
  {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]()" 
              << " (index out of bounds)" << std::endl;
    return m_errobj;
  }

  return m_data[i];
}

template <typename T>
int ArrayList<T>::find(const T& x)
{
  for(int i = 0; i < m_size; i++)
  {
    if(m_data[i] == x)
    {
      return i;
    }
  }

  return -1;
}

template <typename T>
void ArrayList<T>::clear()
{
  delete [] m_data;
  m_data = NULL;
  m_size = 0;
  m_max = 0;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
  insert(x, m_size);
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{
  if(m_data == NULL)
  {
    m_max = 2;
    m_size = 0;
    m_data = new T[m_max];
  }
  if(i <= m_size && i >= 0)
  {
    if(m_size < m_max)
    {
      for(int j = m_size - 1; j >= i; j--)
      {
        m_data[j + 1] = m_data[j];
      }

      m_data[i] = x;
      m_size++;
    }
    else
    {
      m_max *= 2;
      T* tmp = new T[m_max];

      for(int j = 0; j < m_size; j++)
      {
        tmp[j] = m_data[j];
      }

      delete [] m_data;
      m_data = tmp;
      tmp = NULL;
      insert(x, i);
    }
    return;
  }
  std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.insert()" 
            << " (index out of bounds)" << std::endl;
}

template <typename T>
void ArrayList<T>::remove(int i)
{
  if(i < m_size && i >= 0)
  {
    for(int j = i; j < m_size - 1; j++)
    {
      m_data[j] = m_data[j + 1];
    }
    m_size--;

    if(m_size < m_max / 4)
    {
      T* tmp = new T[m_max / 2];

      for(int j = 0; j < m_size; j++)
      {
        tmp[i] = m_data[i];
      }

      m_max /= 2;

      delete [] m_data;
      m_data = tmp;
      tmp = NULL;
    }
    return;
  }
  std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.remove()" 
            << " (index out of bounds)" << std::endl;
}

template <typename T>
void ArrayList<T>::swap(int i, int k)
{
  if(i >= 0 && i < m_size && k >= 0 && k < m_size)
  {
    T tmp = m_data[i];
    m_data[i] = m_data[k];
    m_data[k] = tmp;
    return;
  }
  std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.swap()" 
            << " (index out of bounds)" << std::endl;
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
  if(alist.m_size != 0)
  {
    if(m_max >= m_size + alist.m_size)
    {
      int x = m_size;
      for(int i = 0; i < alist.m_size; i++)
      {
        m_data[i + x] = alist[i];
        m_size++;
      }
    }
    else
    {
      m_max *= 2;
      T* tmp = new T[m_max];

      for(int j = 0; j < m_size; j++)
      {
        tmp[j] = m_data[j];
      }
 
      delete [] m_data;
      m_data = tmp;
      tmp = NULL;

      append(alist);
    }
  }
}

template <typename T>
void ArrayList<T>::purge()
{
  T data;
  for(int i = 0; i < m_size; i++)
  {
    data = m_data[i];
    for(int j = i + 1; j < m_size; j++)
    {
      if(m_data[j] == data)
      {
        remove(j);
        j--;
      }
    }
  }
}
