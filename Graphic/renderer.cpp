#include "renderer.h"

Renderer::Renderer()
{
    glClearColor(0.5, 0.5, 0.5, 1.0);
}

void Tri()
{
    float vertices[] = {
        -0.5f, -0.5f,
        0.5f, -0.5,
        0.0f, 0.5f
    };

    unsigned int VBO, Buffer;

    glGenBuffers(1, &Buffer);
    glBindBuffer(GL_ARRAY_BUFFER, Buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glCreateVertexArrays(1, &VBO);
    glBindVertexArray(1);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

}

void Renderer::FrameBuffer(unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT)
{
    Tri();

    glGenFramebuffers(1, &framebuffer);
    glBindFramebuffer( GL_FRAMEBUFFER, framebuffer );

    glGenTextures(1,&texture);
    glBindTexture( GL_TEXTURE_2D, texture );

    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, 1980, 1080,0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glFramebufferTexture2D( GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);

    glGenRenderbuffers(1, &RBO);
    glBindRenderbuffer(GL_RENDERBUFFER, RBO);
    glRenderbufferStorage( GL_RENDERBUFFER, GL_DEPTH_STENCIL, 1980, 1080);
    glBindRenderbuffer(GL_RENDERBUFFER,0);
    glFramebufferRenderbuffer( GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, RBO);
}

void Renderer::FrameBufferBind()
{
   glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
}

void Renderer::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    
}

void Renderer::FrameBufferUnbind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

Renderer::~Renderer()
{
    glDeleteRenderbuffers(1, &RBO);
    glDeleteTextures(1, &texture);
    glDeleteFramebuffers(1, &framebuffer);
}
