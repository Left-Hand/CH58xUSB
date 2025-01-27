// #include <FrontApp.hpp>

// void FrontApp::render(){
//     Frame & frame = *(oled.fetchFrame());

//     auto v = INA226_GetBusVoltage_uV(&ina) * (1E-6f);
//     auto vs = INA226_GetShuntVoltage_uV(&ina) * (1E-6f);
//     auto a = vs / 0.007f;
//     auto w = v * a;

//     frame.clear();

//     frame.drawString(Vector2i(0,0),floatStr(v,3) + "V");
//     frame.drawString(Vector2i(0,8),floatStr(a,3) + "A");
//     frame.drawString(Vector2i(0,16),floatStr(w,3) + "W");


//     oled.pushStream();
// };

// string floatStr(float val, int fixed) {
//     string str = std::to_string(val);
//     return str.substr(0, str.find(".") + fixed + 1);
// }