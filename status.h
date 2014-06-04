
#ifndef _PWR_STATUS_H
#define  _PWR_STATUS_H

#include <deque>

#include "./types.h"

struct _Status {

  public:
    bool empty() {
        return m_info.empty();
    }
    int pop( PWR_AttrAccessError* ptr ) {
        if ( m_info.empty() ) return PWR_ERR_FAILURE;
        *ptr = m_info.front();
        m_info.pop_front();
        return PWR_ERR_SUCCESS;
    }

    void add( _Obj* obj, PWR_AttrType type, int error  ) {
        PWR_AttrAccessError tmp;
        tmp.obj = obj;
        tmp.type = type;
        tmp.error = error;
        m_info.push_back( tmp ); 
    }
    int clear() {
        m_info.clear();
        return PWR_ERR_SUCCESS;
    }

  private:
    
    std::deque<PWR_AttrAccessError> m_info;
};


#endif