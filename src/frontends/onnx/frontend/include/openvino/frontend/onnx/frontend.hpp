// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "openvino/frontend/extension/conversion.hpp"
#include "openvino/frontend/extension/decoder_transformation.hpp"
#include "openvino/frontend/extension/extension_holder.hpp"
#include "openvino/frontend/extension/telemetry.hpp"
#include "openvino/frontend/frontend.hpp"
#include "openvino/frontend/onnx/visibility.hpp"

namespace ov {
namespace frontend {
namespace onnx {

class ONNX_FRONTEND_API FrontEnd : public ov::frontend::FrontEnd {
public:
    ~FrontEnd() override;
    using Ptr = std::shared_ptr<FrontEnd>;
    std::shared_ptr<ov::Model> convert(const InputModel::Ptr& model) const override;
    void convert(const std::shared_ptr<ov::Model>& partially_converted) const override;
    std::shared_ptr<ov::Model> decode(const InputModel::Ptr& model) const override;
    std::string get_name() const override;
    bool supported_impl(const std::vector<ov::Any>& variants) const override;
    void add_extension(const std::shared_ptr<ov::Extension>& extension) override;

protected:
    InputModel::Ptr load_impl(const std::vector<ov::Any>& params) const override;

    // m_extensions should be the first member here,
    // m_extensions can contain SO Extension (holder for other Extensions),
    // so it should be released last.
    std::vector<Extension::Ptr> m_other_extensions;
    std::vector<DecoderTransformationExtension::Ptr> m_transformation_extensions;
    std::vector<ConversionExtensionBase::Ptr> m_conversion_extensions;
    ExtensionHolder m_extensions;
};

}  // namespace onnx
}  // namespace frontend
}  // namespace ov
