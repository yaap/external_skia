/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkPDFBitmap_DEFINED
#define SkPDFBitmap_DEFINED

#include "include/core/SkData.h"
#include "src/core/SkChecksum.h"

class SkCodec;
class SkImage;
class SkPDFDocument;
struct SkEncodedInfo;
struct SkPDFIndirectReference;

/**
 * Serialize a SkImage as an Image Xobject.
 *  quality > 100 means lossless
 */
SkPDFIndirectReference SkPDFSerializeImage(const SkImage* img,
                                           SkPDFDocument* doc,
                                           int encodingQuality = 101);

class SkPDFBitmap {
public:
    static const SkEncodedInfo& GetEncodedInfo(SkCodec&);
};

struct SkPDFIccProfileKey {
    sk_sp<SkData> fData;
    bool operator==(const SkPDFIccProfileKey& that) const {
        return fData->equals(that.fData.get());
    }
    bool operator!=(const SkPDFIccProfileKey& rhs) const { return !(*this == rhs); }

    struct Hash {
        uint32_t operator()(const SkPDFIccProfileKey& k) const {
            return SkChecksum::Hash32(k.fData->data(), k.fData->size());
        }
    };
};

#endif  // SkPDFBitmap_DEFINED
