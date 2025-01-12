#pragma once

#include <TouchEnginePluginBase.h>

#ifdef __APPLE__
#define NS_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION
#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>
#endif

#include "Thumbnail.h"

class FFGLTouchEngine : public FFGLTouchEnginePluginBase
{
public:
	FFGLTouchEngine();
	~FFGLTouchEngine() override;

	//CFFGLPlugin
	FFResult InitGL(const FFGLViewportStruct* vp) override;
	FFResult ProcessOpenGL(ProcessOpenGLStruct* pGL) override;
	FFResult DeInitGL() override;

private:
#ifdef __APPLE__
//    MTL::Device *pDevice;
#endif

	//TouchEngine IO objects
#ifdef _WIN32
	TouchObject<TED3D11Texture> TEVideoInputD3D;
	TouchObject<TED3D11Texture> TEVideoOutputD3D;
#endif
	TouchObject<TETexture> TEVideoInputTexture;
	TouchObject<TETexture> TEVideoOutputTexture;
	TouchObject<TEFloatBuffer> TEAudioInFloatBuffer1;
	TouchObject<TEFloatBuffer> TEAudioInFloatBuffer2;


#ifdef _WIN32
	//Spout Configs
	std::string SpoutIDOutput;
	Spout OutputInterop;
	bool OutputInteropInitialized = false;
#endif


#ifdef _WIN32
	GLuint SpoutTextureOutput = 0;
#endif

	bool CreateInputTexture(int width, int height);

	void ResumeTouchEngine() override;
	void ClearTouchInstance() override;

	void HandleOperatorLink(const TouchObject<TELinkInfo>& linkInfo) override;
};
