/**********************************************************\

  Auto-generated OOCallerAPI.h

\**********************************************************/

#include <string>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "OOCaller.h"

#ifndef H_OOCallerAPI
#define H_OOCallerAPI

class OOCallerAPI : public FB::JSAPIAuto
{
public:
    OOCallerAPI(OOCallerPtr plugin, FB::BrowserHostPtr host);
    virtual ~OOCallerAPI();

    OOCallerPtr getPlugin();

    // Read/Write property ${PROPERTY.ident}
    std::string get_testString();
    void set_testString(const std::string& val);

    // Read-only property ${PROPERTY.ident}
    std::string get_version();

    // Method callOO
    void callOO(const FB::variant& docUrl);
    
    // Method test-event
    void testEvent(const FB::variant& s);

private:
    OOCallerWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;

    std::string m_testString;
};

#endif // H_OOCallerAPI

