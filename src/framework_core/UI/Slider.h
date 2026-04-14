/*******************************************************************
 *                        Peach-E v0.0.1
 *         Created by Ranyodh Singh Mandur - 🍑 2024-2026
 *
 *              Licensed under the MIT License (MIT).
 *         For more details, see the LICENSE file or visit:
 *               https://opensource.org/licenses/MIT
 *
 *           Peach-E is a free open source game engine
********************************************************************/
#pragma once

#include "ShapePrimitives.h"

namespace PeachCore::PUI {

    struct Slider
    {
        ShapePrimitive m_Shape;  // default called in constructor as rectangular

        explicit
            Slider
            (
                ShapePrimitive fp_Shape = RectShape{}  // pass any shape directly
            )
            :
            m_Shape(fp_Shape)
        {
            //>w<!
        }

    };

}// namespace PeachCore::PUI