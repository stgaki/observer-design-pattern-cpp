#ifndef SUBJECTITF_HPP_
#define SUBJECTITF_HPP_

#include "ObserverItf.hpp"

class SubjectItf {
  
  public:
    virtual void registerObserver(ObserverItf* observer) = 0;
    virtual void removeObserver(ObserverItf* observer) = 0;
    virtual void notifyObservers() = 0;
};

#endif /* SUBJECTITF_HPP_ */