#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <GL/gl.h>
#include <iostream>

class Renderer
{
public:
    Renderer();

    void FrameBuffer(unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT);
    void FrameBufferBind();
    void Draw();
    void FrameBufferUnbind();
    virtual ~Renderer();
    
    inline unsigned int gettexture() {return texture;}


private:
    unsigned int SCR_WIDTH, SCR_HEIGHT;
    unsigned int texture, framebuffer, RBO;
};

#endif // RENDERER_H
