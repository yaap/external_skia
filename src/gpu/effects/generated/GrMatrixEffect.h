/*
 * Copyright 2020 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrMatrixEffect.fp; do not modify.
 **************************************************************************************************/
#ifndef GrMatrixEffect_DEFINED
#define GrMatrixEffect_DEFINED
#include "include/core/SkTypes.h"
#include "include/core/SkM44.h"

#include "src/gpu/GrCoordTransform.h"
#include "src/gpu/GrFragmentProcessor.h"
class GrMatrixEffect : public GrFragmentProcessor {
public:
    static std::unique_ptr<GrFragmentProcessor> Apply(
            const SkMatrix& matrix, std::unique_ptr<GrFragmentProcessor> processor) {
        if (matrix.isIdentity()) {
            return processor;
        }
        SkASSERT(!processor->isSampledWithExplicitCoords());
        SkASSERT(processor->sampleMatrix().fKind == SkSL::SampleMatrix::Kind::kNone);
        return Make(matrix, std::move(processor));
    }
    static std::unique_ptr<GrFragmentProcessor> Make(SkMatrix matrix,
                                                     std::unique_ptr<GrFragmentProcessor> child) {
        return std::unique_ptr<GrFragmentProcessor>(new GrMatrixEffect(matrix, std::move(child)));
    }
    GrMatrixEffect(const GrMatrixEffect& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "MatrixEffect"; }
    SkMatrix matrix;
    int child_index = -1;

private:
    GrMatrixEffect(SkMatrix matrix, std::unique_ptr<GrFragmentProcessor> child)
            : INHERITED(kGrMatrixEffect_ClassID, kNone_OptimizationFlags), matrix(matrix) {
        SkASSERT(child);
        child_index = this->numChildProcessors();
        this->registerChildProcessor(std::move(child));
    }
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    typedef GrFragmentProcessor INHERITED;
};
#endif
