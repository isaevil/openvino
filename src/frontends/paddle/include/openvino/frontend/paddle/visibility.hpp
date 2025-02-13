// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "openvino/frontend/exception.hpp"

#ifdef OPENVINO_STATIC_LIBRARY
#    define PADDLE_API
#    define PADDLE_C_API
#else
#    ifdef ov_paddle_frontend_EXPORTS
#        define PADDLE_API   OPENVINO_CORE_EXPORTS
#        define PADDLE_C_API OPENVINO_EXTERN_C OPENVINO_CORE_EXPORTS
#    else
#        define PADDLE_API   OPENVINO_CORE_IMPORTS
#        define PADDLE_C_API OPENVINO_EXTERN_C OPENVINO_CORE_IMPORTS
#    endif  // ov_paddle_frontend_EXPORTS
#endif      // OPENVINO_STATIC_LIBRARY
