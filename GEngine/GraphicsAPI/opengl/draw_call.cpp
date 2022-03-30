//
// Created by zhanghong50 on 2022/1/26.
//

#include "draw_call.h"


GENG_BEGIN

DrawCall::DrawCall() {
    num_triangle_ = 0;
}
DrawCall::DrawCall(uint32_t n_triangle) {
    num_triangle_ = n_triangle;
}

DrawCall::~DrawCall() {

}

void DrawCall::drawElement() {
    glDrawElements(GL_TRIANGLES, 3 * num_triangle_, GL_UNSIGNED_INT, (void*)0);
}


void DrawCall::drawArrays() {
    glDrawArrays(GL_TRIANGLES, 0, 3* num_triangle_);
}

GENG_END