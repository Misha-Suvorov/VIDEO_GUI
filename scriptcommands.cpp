#include "scriptcommands.h"
#include "senddataframe.h"


ScriptCommands& ScriptCommands::GetInstance() {
    static ScriptCommands instance;
    return instance;
}


void ScriptCommands::SetAngleEncoder_H(float value){
    std::vector<uint8_t> byteArray(4);
    std::memcpy(byteArray.data(), &value, sizeof(float));

    std::vector<uint8_t> payload = {0x00, 0x11, 0x02, 0x00};
    payload.insert(payload.end(), byteArray.begin(), byteArray.end());

    SendDataFrame sendDataFrame;
    sendDataFrame.Send(0x218,0x08, payload);
}


void ScriptCommands::SetAngleEncoder_V(float value){
    std::vector<uint8_t> byteArray(4);
    std::memcpy(byteArray.data(), &value, sizeof(float));

    std::vector<uint8_t> payload = {0x00, 0x21, 0x02, 0x00};
    payload.insert(payload.end(), byteArray.begin(), byteArray.end());

    SendDataFrame sendDataFrame;
    sendDataFrame.Send(0x218,0x08, payload);
}


void ScriptCommands::GetMode(){
    std::vector<uint8_t> payload = {0x00, 0x00, 0x04, 0x01, 0x00, 0x00, 0x00, 0x00};
    SendDataFrame sendDataFrame;
    sendDataFrame.Send(0x118,0x08, payload);
}


void ScriptCommands::SetMode(ModePlatform mode){

    std::vector<uint8_t> payload = {0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,(uint8_t)mode};
    SendDataFrame sendDataFrame;
    sendDataFrame.Send(0x118,0x08, payload);

}


void ScriptCommands::SetLaserEnergy(uint8_t value){
    std::vector<uint8_t> payload = {0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, value};
    SendDataFrame sendDataFrame;
    sendDataFrame.Send(0x248,0x08, payload);
}
