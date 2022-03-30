
//
// Created by zhanghong50 on 2022/1/13.
//

#ifndef MYENGINE_STATUS_CALL_H
#define MYENGINE_STATUS_CALL_H

#include "graphic_predeclared.h"
#include "RenderModules/status_mod.h"

GENG_BEGIN

class StatusCall : public StatusModule{
private:
public:
    StatusCall();
    ~StatusCall();

    void setFaceCull(const int32_t & var) override;
    void checkFaceCull(int32_t & var) override;

    void setDepthTest(const int32_t & var) override;
    void checkDepthTest(int32_t & var) override;

    void clearColorBuffer() override;
    void clearDepthBuffer() override;
};

GENG_END

#endif //MYENGINE_STATUS_CALL_H
