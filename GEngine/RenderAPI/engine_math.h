//
// Created by zhanghong50 on 2022/1/13.
//

#ifndef MYENGINE_ENGINE_MATH_H
#define MYENGINE_ENGINE_MATH_H

#include "general_include.h"
#include "glm/detail/type_mat.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <math.h>

GENG_BEGIN

// vector
typedef glm::vec3 GVec3;
typedef glm::vec2 GVec2;
typedef glm::vec4 GVec4;

typedef glm::quat GQuat;

// matrix
typedef glm::mat3x3 GMat3;
typedef glm::mat4x4 GMat4;
typedef glm::mat2x2 GMat2;

// functions
template <typename T>
inline T GDot (T const& vec1, T const& vec2){
    return glm::dot(vec1, vec2);
}

template <typename T>
inline T GNormalize (T const& vec){
    return glm::normalize(vec);
}

template <typename T>
inline T GCross (T const& vec1, T const& vec2){
    return glm::cross(vec1, vec2);
}

template <typename T>
inline T GRadians (T const& val){
    return glm::radians(val);
}

//TODO
// translation
template <typename T>
inline T GTranslate (T const& mat, GVec3 const& vec){
    return glm::translate(mat, vec);
}

// scaling
template <typename T>
inline T GScale (T const& mat, GVec3 const& vec){
    return glm::scale(mat, vec);
}

// translation
template <typename T>
inline T GRotate (T const& mat, float angle, GVec3 const& vec){
    return glm::rotate(mat, GRadians(angle), vec);
}

// lookAt transformation
inline GMat4 GLookAt(GVec3 const & pos, GVec3 const& center, GVec3 const& up){
    return glm::lookAt(pos, center, up);
}

// perspective transformation
template <typename T>
inline GMat4 GPerspective(T const& fovy, T const& ratio, T const& near, T const& far){
    return glm::perspective(fovy, ratio, near, far);
}

// orth
template <typename T>
inline GMat4 GOrtho(T const& left, T const& right, T const& bottom){
    return glm::ortho(left, right, bottom);
}

// inverse
template <typename T>
inline T GInverse(T const & mat){
    return glm::inverse(mat);
}

// transpose
template <typename T>
inline T Gtranspose(T const & mat){
    return glm::transpose(mat);
}

GENG_END

#endif //MYENGINE_ENGINE_MATH_H
