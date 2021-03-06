/*!
 * \file
 * \brief 
 * \author Joanna,,,
 */

#ifndef CORRESPONDENCESVIEWER_HPP_
#define CORRESPONDENCESVIEWER_HPP_

#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
#include "Property.hpp"
#include "EventHandler2.hpp"

#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

#include <Types/PointXYZSHOT.hpp>


namespace Processors {
namespace CorrespondencesViewer {

/*!
 * \class CorrespondencesViewer
 * \brief CorrespondencesViewer processor class.
 *
 * CorrespondencesViewer processor.
 */
class CorrespondencesViewer: public Base::Component {
public:
	/*!
	 * Constructor.
	 */
	CorrespondencesViewer(const std::string & name = "CorrespondencesViewer");

	/*!
	 * Destructor
	 */
	virtual ~CorrespondencesViewer();

	/*!
	 * Prepare components interface (register streams and handlers).
	 * At this point, all properties are already initialized and loaded to 
	 * values set in config file.
	 */
	void prepareInterface();

protected:

	/*!
	 * Connects source to given device.
	 */
	bool onInit();

	/*!
	 * Disconnect source from device, closes streams, etc.
	 */
	bool onFinish();

	/*!
	 * Start component
	 */
	bool onStart();

	/*!
	 * Stop component
	 */
	bool onStop();

	void display();
	void on_spin();

	Base::EventHandler2 h_display;
	Base::EventHandler2 h_on_spin;

	Base::DataStreamIn<pcl::PointCloud<pcl::PointXYZRGB>::Ptr> in_cloud;
	Base::DataStreamIn<pcl::PointCloud<PointXYZSHOT>::Ptr> in_shots;

	pcl::visualization::PCLVisualizer * viewer;
	
	int v1, v2;


};

} //: namespace CorrespondencesViewer
} //: namespace Processors

/*
 * Register processor component.
 */
REGISTER_COMPONENT("CorrespondencesViewer", Processors::CorrespondencesViewer::CorrespondencesViewer)

#endif /* CORRESPONDENCESVIEWER_HPP_ */
