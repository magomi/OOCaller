/**********************************************************\

  Auto-generated OOCallerAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include <stdlib.h>
#include "OOCallerAPI.h"

///////////////////////////////////////////////////////////////////////////////
/// @fn OOCallerAPI::OOCallerAPI(OOCallerPtr plugin, FB::BrowserHostPtr host)
///
/// @brief  Constructor for your JSAPI object.  You should register your methods, properties, and events
///         that should be accessible to Javascript from here.
///
/// @see FB::JSAPIAuto::registerMethod
/// @see FB::JSAPIAuto::registerProperty
/// @see FB::JSAPIAuto::registerEvent
///////////////////////////////////////////////////////////////////////////////
OOCallerAPI::OOCallerAPI(OOCallerPtr plugin, FB::BrowserHostPtr host) : m_plugin(plugin), m_host(host)
{
    registerMethod("callOO",      make_method(this, &OOCallerAPI::callOO));
    registerMethod("testEvent", make_method(this, &OOCallerAPI::testEvent));

    // Read-write property
    registerProperty("testString",
                     make_property(this,
                        &OOCallerAPI::get_testString,
                        &OOCallerAPI::set_testString));

    // Read-only property
    registerProperty("version",
                     make_property(this,
                        &OOCallerAPI::get_version));
    
    
    registerEvent("onfired");    
}

///////////////////////////////////////////////////////////////////////////////
/// @fn OOCallerAPI::~OOCallerAPI()
///
/// @brief  Destructor.  Remember that this object will not be released until
///         the browser is done with it; this will almost definitely be after
///         the plugin is released.
///////////////////////////////////////////////////////////////////////////////
OOCallerAPI::~OOCallerAPI()
{
}

///////////////////////////////////////////////////////////////////////////////
/// @fn OOCallerPtr OOCallerAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
OOCallerPtr OOCallerAPI::getPlugin()
{
    OOCallerPtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}



// Read/Write property testString
std::string OOCallerAPI::get_testString()
{
    return m_testString;
}
void OOCallerAPI::set_testString(const std::string& val)
{
    m_testString = val;
}

// Read-only property version
std::string OOCallerAPI::get_version()
{
    return "CURRENT_VERSION";
}

// Method callOO
void OOCallerAPI::callOO(const FB::variant& docUrl)
{
    std::string docUrlStr = docUrl.convert_cast<std::string>();
    std::string execStr("/usr/bin/oowriter ");
    execStr += docUrlStr;
    system(execStr.c_str());
}

void OOCallerAPI::testEvent(const FB::variant& var)
{
    FireEvent("onfired", FB::variant_list_of(var)(true)(1));
}

