#include "GUI.h"
// http://cegui.org.uk/content/getting-started

CEGUI::OpenGL3Renderer* GUI::m_renderer = nullptr;

void GUI::init(const std::string& resourceDirectory) {
	// check if the renderer and system were already initialized
	if (m_renderer == nullptr) {
		m_renderer = &CEGUI::OpenGL3Renderer::bootstrapSystem();

		CEGUI::DefaultResourceProvider* rp = static_cast<CEGUI::DefaultResourceProvider*>(CEGUI::System::getSingleton().getResourceProvider());
		// resourceDirectory is GUI
		rp->setResourceGroupDirectory("imagesets", resourceDirectory + "/imagesets/");
		rp->setResourceGroupDirectory("schemes", resourceDirectory + "/schemes/");
		rp->setResourceGroupDirectory("fonts", resourceDirectory + "/fonts/");
		rp->setResourceGroupDirectory("layouts", resourceDirectory + "/layouts/");
		rp->setResourceGroupDirectory("looknfeels", resourceDirectory + "/looknfeel/");
		rp->setResourceGroupDirectory("lua_scripts", resourceDirectory + "/lua_scripts/");

		CEGUI::ImageManager::setImagesetDefaultResourceGroup("imagesets");
		CEGUI::Scheme::setDefaultResourceGroup("schemes");
		CEGUI::Font::setDefaultResourceGroup("fonts");
		CEGUI::WidgetLookManager::setDefaultResourceGroup("looknfeels");
		CEGUI::WindowManager::setDefaultResourceGroup("layouts");
		CEGUI::ScriptModule::setDefaultResourceGroup("lua_scripts");
	}

	m_context = &CEGUI::System::getSingleton().createGUIContext(m_renderer->getDefaultRenderTarget());
	m_root = CEGUI::WindowManager::getSingleton().createWindow("DefaultWindow", "root");
	m_context->setRootWindow(m_root);
}

void GUI::destroy() {
	CEGUI::System::getSingleton().destroyGUIContext(*m_context);
}

void GUI::draw() {
	m_renderer->beginRendering();
	m_context->draw();
	m_renderer->endRendering();

	glDisable(GL_SCISSOR_TEST);
}

void GUI::loadScheme(const std::string& schemeFile) {
	CEGUI::SchemeManager::getSingleton().createFromFile(schemeFile);
}

// don't redeclare default parameter
CEGUI::Window* GUI::createWidget(const std::string& type, float wPerc, float wPix, float xPerc, float xPix, float yPerc, float yPix, float zPerc, float zPix, const std::string& name /*= ""*/) {
	CEGUI::Window* newWindow = CEGUI::WindowManager::getSingleton().createWindow(type, name);
	m_root->addChild(newWindow);
	setWidgetDestRect(newWindow, wPerc, wPix, xPerc, xPix, yPerc, yPix, zPerc, zPix);
	return newWindow;
}

void GUI::setWidgetDestRect(CEGUI::Window* widget, float wPerc, float wPix, float xPerc, float xPix, float yPerc, float yPix, float zPerc, float zPix) {
	widget->setPosition(CEGUI::UVector2(CEGUI::UDim(xPerc, xPix), CEGUI::UDim(yPerc, yPix)));
	widget->setSize(CEGUI::USize(CEGUI::UDim(zPerc, zPix), CEGUI::UDim(wPerc, wPix)));
}

void GUI::setFont(const std::string& fontFile) {
	CEGUI::FontManager::getSingleton().createFromFile(fontFile + ".font");
	m_context->setDefaultFont(fontFile);
}