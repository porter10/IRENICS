#include <Graphic/renderer.h>
#include <Editor/window.h>
#include <Editor/editor.h>

int main(void)
{
    Window window;

    gladLoadGL();
    Renderer render;
    render.FrameBuffer(1980, 1080);

    Editor editor(window.getwindow());

    while (window.windowopen())
    {
        window.windowevent();

        render.FrameBufferBind();
        render.Draw();
        render.FrameBufferUnbind();
        
        editor.UI(render.gettexture());

        window.swapbuffer();
    }   

    return 0;
}