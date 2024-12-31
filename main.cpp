#include <sol/sol.hpp>
#include <lua.hpp>
#include <string>

struct vars {
    int boop = 0;
};

std::string script_str = "print(\"hello, world!\")";


int main() {

    // test 1
    {
        sol::state lua;
        int x = 0;
        lua.set_function("beep", [&x]{ ++x; });
        lua.script("beep()");
        assert(x == 1);
    }

    // test 2
    {
        sol::state lua;
        lua.new_usertype<vars>("vars", "boop", &vars::boop);
        lua.script("beep = vars.new()\n"
                "beep.boop = 1");
        assert(lua.get<vars>("beep").boop == 1);
    }

    // test 3
    {
        sol::state lua;

        // Open standard libraries (print, etc.)
        lua.open_libraries(sol::lib::base);
        lua.script(script_str);
    }

    return 0;
}
