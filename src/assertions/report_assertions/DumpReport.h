/* -*- mode: c++ -*-
 * Kaleidoscope-Simulator -- A C++ testing API for the Kaleidoscope keyboard 
 *                         firmware.
 * Copyright (C) 2019  noseglasses (shinynoseglasses@gmail.com)
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "assertions/ReportAssertion_.h"

#include "kaleidoscope/key_defs.h"

namespace kaleidoscope {
namespace simulator {
namespace assertions {

/// @brief Asserts nothing but dumps the current report instead.
///
template<typename _ReportType>
class DumpReport {
   
   public:
      
      KT_ASSERTION_STD_CONSTRUCTOR(DumpReport)
   
   private:
      
      class Assertion : public ReportAssertion_<_ReportType> {
            
         public:

            virtual void describe(const char *add_indent = "") const override {
               this->getReport().dump(*simulator_, add_indent);
            }

            virtual void describeState(const char *add_indent = "") const {
               this->describe(add_indent);
            }

            virtual bool evalInternal() override {
               this->describe();
               return true;
            }

      };
   
   KT_AUTO_DEFINE_ASSERTION_INVENTORY(DumpReport)
};

} // namespace assertions
} // namespace simulator
} // namespace kaleidoscope