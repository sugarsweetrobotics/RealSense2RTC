// -*- C++ -*-
/*!
 * @file  RealSense2RTC.cpp
 * @brief Intel Real Sense 3D Component
 * @date $Date$
 *
 * @author Sugar Swee Robotics
 *
 * GPL
 *
 * $Id$
 */

#include "RealSense2RTC.h"

// Module specification
// <rtc-template block="module_spec">
static const char* realsense2rtc_spec[] =
  {
    "implementation_id", "RealSense2RTC",
    "type_name",         "RealSense2RTC",
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
RealSense2RTC::RealSense2RTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_rgbdCameraImageOut("rgbdCameraImage", m_rgbdCameraImage)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
RealSense2RTC::~RealSense2RTC()
{
}



RTC::ReturnCode_t RealSense2RTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("rgbdCameraImage", m_rgbdCameraImageOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("debug", m_debug, "1");
  bindParameter("width", m_width, "640");
  bindParameter("height", m_height, "480");
  bindParameter("depthWidth", m_depthWidth, "640");
  bindParameter("depthHeight", m_depthHeight, "480");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t RealSense2RTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RealSense2RTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RealSense2RTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t RealSense2RTC::onActivated(RTC::UniqueId ec_id)
{
	m_rgbdCameraImage.data.cameraImage.image.format = Img::CF_GRAY;

	m_rgbdCameraImage.data.cameraImage.intrinsic.distortion_coefficient.length(1);
	m_rgbdCameraImage.data.cameraImage.intrinsic.distortion_coefficient[0] = 0;
	m_rgbdCameraImage.data.cameraImage.intrinsic.matrix_element[0] = 0;
	m_rgbdCameraImage.data.cameraImage.intrinsic.matrix_element[1] = 0;
	m_rgbdCameraImage.data.cameraImage.intrinsic.matrix_element[2] = 0;
	m_rgbdCameraImage.data.cameraImage.intrinsic.matrix_element[3] = 0;
	m_rgbdCameraImage.data.cameraImage.intrinsic.matrix_element[4] = 0;
	m_rgbdCameraImage.data.cameraImage.extrinsic[0][0] = 0;
	m_rgbdCameraImage.data.cameraImage.extrinsic[0][1] = 0;
	m_rgbdCameraImage.data.cameraImage.extrinsic[0][2] = 0;
	m_rgbdCameraImage.data.cameraImage.extrinsic[0][3] = 0;
	m_rgbdCameraImage.data.cameraImage.extrinsic[1][0] = 0;
	m_rgbdCameraImage.data.cameraImage.extrinsic[1][1] = 0;
	m_rgbdCameraImage.data.cameraImage.extrinsic[1][2] = 0;
	m_rgbdCameraImage.data.cameraImage.extrinsic[1][3] = 0;
	m_rgbdCameraImage.data.cameraImage.extrinsic[2][0] = 0;
	m_rgbdCameraImage.data.cameraImage.extrinsic[2][1] = 0;
	m_rgbdCameraImage.data.cameraImage.extrinsic[2][2] = 0;
	m_rgbdCameraImage.data.cameraImage.extrinsic[2][3] = 0;
	m_rgbdCameraImage.data.cameraImage.extrinsic[3][0] = 0;
	m_rgbdCameraImage.data.cameraImage.extrinsic[3][1] = 0;
	m_rgbdCameraImage.data.cameraImage.extrinsic[3][2] = 0;
	m_rgbdCameraImage.data.cameraImage.extrinsic[3][3] = 0;
	m_rgbdCameraImage.data.cameraImage.captured_time.sec = 0;
	m_rgbdCameraImage.data.cameraImage.captured_time.nsec = 0;


	m_rgbdCameraImage.data.depthImage.verticalFOV = 0.0;
	m_rgbdCameraImage.data.depthImage.horizontalFOV = 0.0;

	m_rgbdCameraImage.data.geometry.pose.position.x = 0;
	m_rgbdCameraImage.data.geometry.pose.position.y = 0;
	m_rgbdCameraImage.data.geometry.pose.position.z = 0;
	m_rgbdCameraImage.data.geometry.pose.orientation.p = 0;
	m_rgbdCameraImage.data.geometry.pose.orientation.r = 0;
	m_rgbdCameraImage.data.geometry.pose.orientation.y = 0;




	this->m_rgbdCameraImage.data.cameraImage.image.width = m_width;
	this->m_rgbdCameraImage.data.cameraImage.image.height = m_height;
	this->m_rgbdCameraImage.data.cameraImage.image.raw_data.length(m_width*m_height * 3);


	m_rgbdCameraImage.data.depthImage.width = m_depthWidth;
	m_rgbdCameraImage.data.depthImage.height = m_depthHeight;

	m_rgbdCameraImage.data.depthImage.raw_data.length(m_depthWidth * m_depthHeight);

	//Instruct pipeline to start streaming with the requested configuration
	//Add desired streams to configuration
	cfg_.enable_stream(RS2_STREAM_COLOR, m_width, m_height, RS2_FORMAT_BGR8, 30);
	cfg_.enable_stream(RS2_STREAM_DEPTH, m_depthWidth, m_depthHeight, RS2_FORMAT_Z16, 30);
	
	
	prof_ = pipe_.start(cfg_);
	rs2::depth_sensor ds = prof_.get_device().query_sensors().front().as<rs2::depth_sensor>();
	scale_ = ds.get_depth_scale();
  return RTC::RTC_OK;
}


RTC::ReturnCode_t RealSense2RTC::onDeactivated(RTC::UniqueId ec_id)
{

	pipe_.stop();
  return RTC::RTC_OK;
}


RTC::ReturnCode_t RealSense2RTC::onExecute(RTC::UniqueId ec_id)
{
	const int width = m_rgbdCameraImage.data.cameraImage.image.width;
	const int height = m_rgbdCameraImage.data.cameraImage.image.height;
	

	frames_ = pipe_.wait_for_frames();
	

	//Get each frame
	rs2::frame color_frame = frames_.get_color_frame();

	const uint8_t* data = (const uint8_t*)color_frame.get_data();
	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			int index = h * width * 3 + w * 3;
			m_rgbdCameraImage.data.cameraImage.image.raw_data[index + 0] = data[index + 2];
			m_rgbdCameraImage.data.cameraImage.image.raw_data[index + 1] = data[index + 1];
			m_rgbdCameraImage.data.cameraImage.image.raw_data[index + 2] = data[index + 0];
		}
	}
	rs2::frame depth_frame = frames_.get_depth_frame();
	const int dwidth = m_rgbdCameraImage.data.cameraImage.image.width;
	const int dheight = m_rgbdCameraImage.data.cameraImage.image.height;
	const uint8_t* ddata = (const uint8_t*)depth_frame.get_data();

	for (int h = 0; h < dheight; h++) {
		for (int w = 0; w < dwidth; w++) {
			int index = h * dwidth + w;
			m_rgbdCameraImage.data.depthImage.raw_data[index] = ddata[index] * scale_;
		}
	}

	setTimestamp(m_rgbdCameraImage);
	m_rgbdCameraImageOut.write();
	return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t RealSense2RTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RealSense2RTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RealSense2RTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RealSense2RTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t RealSense2RTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void RealSense2RTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(realsense2rtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<RealSense2RTC>,
                             RTC::Delete<RealSense2RTC>);
  }
  
};


