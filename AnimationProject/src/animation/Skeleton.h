#ifndef _H_SKELETON_
#define _H_SKELETON_

#include <vector>
#include <iostream>

#include "Pose.h"
#include "../math/mat4.h"

class Skeleton
{

protected:
	Pose mRestPose;
	Pose mBindPose;
	std::vector<mat4> mInvBindPose;
	std::vector<std::string> mJointNames;
	void UpdateInverseBindPose();

public:
	Skeleton();
	Skeleton(const Pose& rest, const Pose& bind, const std::vector<std::string>& names);
	void Set(const Pose& rest, const Pose& bind, const std::vector<std::string>& names);
	Pose& GetBindPose();
	Pose& GetRestPose();
	std::vector<mat4>& GetInvBindPose();
	std::vector<std::string>& GetJointNames();
	std::string& GetJointName(unsigned int index);
};

#endif // !_H_SKELETON_
