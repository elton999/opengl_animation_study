#ifndef _H_GLTFLOADER_
#define _H_GLTFLOADER_

#include "cgltf.h"
#include "animation/Pose.h"
#include "animation/Clip.h"

cgltf_data* LoadGLTFGFFile(const char* path);
void FreeGLTFFile(cgltf_data* handle);

Pose LoadRestPose(cgltf_data* data);
std::vector<std::string> LoadJointNames(cgltf_data* data);
std::vector<Clip> LoadAnimationClips(cgltf_data* data);

#endif // !_H_GLTFLOADER_