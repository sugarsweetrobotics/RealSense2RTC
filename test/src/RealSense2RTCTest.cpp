// -*- C++ -*-
/*!
 * @file  RealSense2RTCTest.cpp
 * @brief Intel Real Sense 3D Component
 * @date $Date$
 *
 * @author Sugar Swee Robotics
 *
 * GPL
 *
 * $Id$
 */

#include "RealSense2RTCTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* realsense2rtc_spec[] =
  {
    "implementation_id", "RealSense2RTCTest",
    "type_name",         "RealSense2RTCTest",
    "description",       "Intel Real Sense 3D Component",
    "version",           "1.0.0",
    "vendor",            "Sugar Sweet Robotics",
    "category",          "Sensor",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.debug", "1",
    "conf.default.width", "640",
    "conf.default.height", "480",

    // Widget
    "conf.__widget__.debug", "text",
    "conf.__widget__.width", "text",
    "conf.__widget__.height", "text",
    // Constraints

    "conf.__type__.debug", "int",
    "conf.__type__.width", "int",
    "conf.__type__.height", "int",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
RealSense2RTCTest::RealSense2RTCTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_rgbdCameraImageOut("rgbdCameraImage", m_rgbdCameraImage)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
RealSense2RTCTest::~RealSense2RTCTest()
{
}



RTC::ReturnCode_t RealSense2RTCTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("rgbdCameraImage", m_rgbdCameraImageIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("debug", m_debug, "1");
  bindParameter("width", m_width, "640");
  bindParameter("height", m_height, "480");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t RealSense2RTCTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RealSense2RTCTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RealSense2RTCTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t RealSense2RTCTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t RealSense2RTCTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t RealSense2RTCTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t RealSense2RTCTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RealSense2RTCTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RealSense2RTCTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RealSense2RTCTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RealSense2RTCTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void RealSense2RTCTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(realsense2rtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<RealSense2RTCTest>,
                             RTC::Delete<RealSense2RTCTest>);
  }
  
};


