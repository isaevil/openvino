// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "mkldnn/ie_mkldnn.h"
#include "cpu_types.h"

#include <ie_layouts.h>
#include <ie_blob.h>

namespace MKLDNNPlugin {

class MemoryDesc;
class DnnlMemoryDesc;
class BlockedMemoryDesc;
class DnnlBlockedMemoryDesc;
class CpuBlockedMemoryDesc;
class MKLDNNMemory;

class MemoryDescUtils {
public:
    MemoryDescUtils() = delete;

    /**
     * @brief Converts MemoryDesc to DnnlMemoryDesc
     * @param desc MemoryDesc to be converted
     * @return converted DnnlMemoryDesc
     */
    static std::shared_ptr<DnnlMemoryDesc> convertToDnnlMemoryDesc(const std::shared_ptr<MemoryDesc> &desc);

    /**
     * @brief Converts MemoryDesc to DnnlBlockedMemoryDesc
     * @param desc MemoryDesc to be converted
     * @return converted DnnlBockedMemoryDesc
     */
    static DnnlBlockedMemoryDesc convertToDnnlBlockedMemoryDesc(const MemoryDesc& desc);

    /**
     * @brief Converts InferenceEngine::TensorDesc to CpuBlockedMemoryDesc
     * @param desc InferenceEngine::TensorDesc to be converted
     * @return converted CpuBlockedMemoryDesc
     */
    static CpuBlockedMemoryDesc convertToCpuBlockedMemoryDesc(const InferenceEngine::TensorDesc& desc);

    /**
     * @brief Converts InferenceEngine::TensorDesc to DnnlBlockedMemoryDesc
     * @param desc InferenceEngine::TensorDesc to be converted
     * @return converted DnnlBlockedMemoryDesc
     */
    static DnnlBlockedMemoryDesc convertToDnnlBlockedMemoryDesc(const InferenceEngine::TensorDesc& desc);

    /**
     * @brief Converts MemoryDesc to BlockedMemoryDesc
     * @param desc MemoryDesc to be converted
     * @return converted BlockedMemoryDesc
     */
    static std::shared_ptr<BlockedMemoryDesc> convertToBlockedMemoryDesc(const std::shared_ptr<MemoryDesc> &desc);

    /**
     * @brief Creates InferenceEngine::Blob from MKLDNNMemory with the memory reuse
     * @param desc MKLDNNMemory from which will be created InferenceEngine::Blob
     * @return pointer to InferenceEngine::Blob
     */
    static InferenceEngine::Blob::Ptr interpretAsBlob(const MKLDNNMemory& mem);

    /**
     * @brief Converts MemoryDesc to InferenceEngine::TensorDesc
     * @param desc MemoryDesc to be converted
     * @return converted InferenceEngine::TensorDesc
     */
    static InferenceEngine::TensorDesc convertToTensorDesc(const MemoryDesc& desc);

    /**
     * @brief Makes a dummy descriptor where all undefined values are replaced with the smallest value between the parameter and the upper bound dim
     * @param desc MemoryDesc from which the new descriptor is generated
     * @param dummyVal Dim value to replace undefined dimensions
     * @return a new MemoryDesc with dummy values instead of undefined dims
     */
     static std::shared_ptr<MemoryDesc> makeDummyDesc(const MemoryDesc& desc, Dim dummyVal = 64);

    /**
    * @brief Makes a static dummy shape where all undefined values are replaced with the smallest value between the parameter and the upper bound dim
    * @param shape a shape from which the new static shape is generated
    * @param dummyVal Dim value to replace undefined dimensions
    * @return a new Shape with dummy values instead of undefined dims
    */
    static Shape makeDummyShape(const Shape& shape, Dim dummyVal = 64);

    /**
     * @brief Converts dim to string, undefined dim represented as ?
     * @param dim Dim to be converted
     * @return dim as string
     */
    static std::string dim2str(Dim dim);

    /**
     * @brief Converts dims to string, undefined dim represented as ?
     * @param dim Dims to be converted
     * @return dims as string
     */
    static std::string dims2str(const VectorDims& dims);
};

}  // namespace MKLDNNPlugin
