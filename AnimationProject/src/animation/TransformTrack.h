#ifndef _H_TRANSFORM_TRACK_
#define _H_TRANFORM_TRACK_

#include "Track.h"
#include "../math/Transform.h"

class TransformTrack
{
protected:
	unsigned int mId;
	VectorTrack mPosition;
	QuaternionTrack mRotation;
	VectorTrack mScale;

public:
	TransformTrack();
	unsigned int GetId();
	void SetId(unsigned int id);
	VectorTrack& GetPosition();
	QuaternionTrack& GetRotationTrack();
	VectorTrack& GetScaleTrack();
	float GetStartTime();
	float GetEndTime();
	bool IsValid();
	Transform Sample(const Transform& ref, float time, bool looping);
};

#endif // !_H_TRANSFORM_TRACK_
