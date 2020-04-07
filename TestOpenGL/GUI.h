#pragma once

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/OpenGL/GL3Renderer.h>

// http://cegui.org.uk/content/getting-started

class GUI {
public:
	void init(const std::string& resourceDirectory);
	void destroy();

	void draw();

	void loadScheme(const std::string& schemeFile);
	void setFont(const std::string& fontFile);
	CEGUI::Window* createWidget(const std::string& type, float wPerc, float wPix, float xPerc, float xPix, float yPerc, float yPix, float zPerc, float zPix, const std::string& name = "");
	static void setWidgetDestRect(CEGUI::Window* widget, float wPerc, float wPix, float xPerc, float xPix, float yPerc, float yPix, float zPerc, float zPix);

	// Getters
	static CEGUI::OpenGL3Renderer* getRenderer() { return m_renderer; }
	CEGUI::GUIContext* getContext() { return m_context; }

private:
	static CEGUI::OpenGL3Renderer* m_renderer;
	CEGUI::GUIContext* m_context = nullptr;
	CEGUI::Window* m_root = nullptr;
};