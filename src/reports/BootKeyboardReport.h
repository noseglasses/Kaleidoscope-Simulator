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

#include "kaleidoscope/key_defs.h"
#include "papilio/src/reports/BootKeyboardReport_.h"

// Undefine some macros defined by Arduino
//
#undef min
#undef max

#include <vector>
#include <stdint.h>
#include <ostream>

namespace kaleidoscope {
namespace simulator {
   
class Simulator;
  
/// @brief An interface hat facilitates analyzing boot keyboard reports.
///
class BootKeyboardReport : public papilio::BootKeyboardReport_ {
   
   public:
      
      typedef HID_BootKeyboardReport_Data_t ReportDataType;
      
      static constexpr uint8_t hid_report_type_ = HID_REPORTID_KEYBOARD;
      
      /// @brief Default consturctor.
      /// @details Creates an empty report.
      ///
      BootKeyboardReport();
      
      /// @brief Constructs based on a raw pointer to report data.
      /// @details Only use this if you know what you are doning!
      /// @param data The address where the report data starts.
      ///
      BootKeyboardReport(const void *data);
      
      /// @brief Constructs based on a report data object.
      /// @param report_data The report data object to read.
      ///
      BootKeyboardReport(const ReportDataType &report_data);
      
      virtual std::shared_ptr<Report_> clone() const override;
      
      /// @brief Checks equality with another key report.
      /// @param other Another key report to compare with.
      /// @returns [bool] True if both reports are equal.
      ///
      virtual bool equals(const papilio::Report_ &other) const override;
      
      /// @brief Checks if a keycode is active in the keyboard report.
      /// @param keycode The keycode to check for.
      /// @returns [bool] True if the given keycode is active.
      ///
      virtual bool isKeycodeActive(uint8_t keycode) const override;
      
      /// @brief Checks if the keycode of a given Key is active in the keyboard report.
      /// @details Please note that the flags part of the Key is ignored.
      /// @param key The Key whose keycode to check for.
      /// @returns [bool] True if the given Key's keycode is active.
      ///
      virtual bool isKeyActive(const Key &key) const override;
      
      /// @brief Retreives a list of all keycodes that are active in the
      ///        keyboard report.
      /// @returns A vector of keycodes.
      ///
      virtual std::vector<uint8_t> getActiveKeycodes() const override;
      
      /// @brief Checks if a modifier keycode is active in the keyboard report.
      /// @param keycode The modifier keycode to check for.
      /// @returns [bool] True if the given modifier keycode is active.
      ///
      virtual bool isModifierKeycodeActive(uint8_t modifier) const override;
      
      /// @brief Checks if the modifier keycode of a given Key is active in the keyboard report.
      /// @details Please note that the flags part of the Key is ignored.
      /// @param key The Key whose modifier keycode to check for.
      /// @returns [bool] True if the given Key's modifier keycode is active.
      ///
      virtual bool isModifierKeyActive(const Key &key) const override;
      
      /// @brief Checks if any modifier keycode is active.
      /// @returns [bool] True if any modifier keycode is active, false otherwise.
      ///
      virtual bool isAssertAnyModifierActive() const override;
      
      /// @brief Checks if any key keycode is active.
      /// @returns [bool] True if any key keycode is active, false otherwise.
      ///
      virtual bool isAnyKeyActive() const override;
      
      /// @brief Retreives a list of active modifier keycodes.
      /// @returns A list of active modifier keycodes.
      ///
      virtual std::vector<uint8_t> getActiveModifiers() const override;
      
      /// @brief Checks if the report is empty.
      /// @details Empty means neither key nor modifier keycodes are active.
      ///
      virtual bool isEmpty() const override;
      
      /// @brief Writes a formatted representation of the keyboard report 
      ///        to the simulator's log stream.
      /// @param add_indent An additional indentation string.
      ///
      virtual void dump(const Simulator &simulator, const char *add_indent = "") const override;
      
      /// @brief Associates the object with new report data.
      /// @param report_data The new report data struct.
      ///
      void setReportData(const ReportDataType &report_data);
      
      const ReportDataType& getReportData() const { return report_data_; }
      
      static const char *typeString() { return "keyboard"; }
      virtual const char *getTypeString() const override { return typeString(); }
      
   private:
   
      ReportDataType report_data_;
};

} // namespace simulator
} // namespace kaleidoscope
