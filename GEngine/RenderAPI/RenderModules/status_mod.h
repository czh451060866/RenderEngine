//
// Created by HongZh on 2022/02/25, 10:59:02
//

#ifndef MYENGINE_STATUS_MODULE_H
#define MYENGINE_STATUS_MODULE_H

#include "general_include.h"

GENG_BEGIN


class StatusModule {
public:
  virtual ~StatusModule();
  static std::shared_ptr<StatusModule> getInstancePtr();

  virtual void setFaceCull(const int32_t & var) = 0;
  virtual void checkFaceCull(int32_t & var) = 0;
  virtual void setDepthTest(const int32_t & var) = 0;
  virtual void checkDepthTest(int32_t & var) = 0;

  virtual void clearColorBuffer() = 0;
  virtual void clearDepthBuffer() = 0;
protected:
  StatusModule();
};

class StatusManager{
public:
  void clearColorBuffer();
  void clearDepthBuffer();
  void clearAllBuffer();

  void saveCurStatus(); // save status
  void resetStatus(); // reset

  StatusManager();
  ~StatusManager();
private:
  int32_t CullFace_ = 0;
  int32_t DepthTest_ = 1;
  int32_t Blend = 1;
  std::shared_ptr<StatusModule> status_ptr_;
  //TODO
};


GENG_END

#endif // MYENGINE_STATUS_MODULE_H