#include "scriptcommands.h"
#include "qthread.h"
#include "senddataframe.h"

ScriptCommands &ScriptCommands::GetInstance()
{
    static ScriptCommands instance;
    return instance;
}

/**
 * @brief Встановлює значення кута енкодера по горизонталі в градусах
 *
 * @param value Значення енкодеру по горизонталі (градуси)
 *
 */
void ScriptCommands::SetAngleEncoder_H(float value)
{
    std::vector<uint8_t> byteArray(4);
    std::memcpy(byteArray.data(), &value, sizeof(float));

    std::vector<uint8_t> payload = {0x00, 0x11, 0x02, 0x00};
    payload.insert(payload.end(), byteArray.begin(), byteArray.end());

    //SendDataFrame::getInstance().Send(0x218, 0x08, payload);
    SendDataFrame::getInstance().AddCanFrame(0x218, 0x08, payload);
}

/**
 * @brief Встановлює значення кута енкодера по вертикалі в градусах
 *
 * @param value Значення енкодеру по вертикалі (градуси)
 *
 */
void ScriptCommands::SetAngleEncoder_V(float value)
{
    std::vector<uint8_t> byteArray(4);
    std::memcpy(byteArray.data(), &value, sizeof(float));

    std::vector<uint8_t> payload = {0x00, 0x21, 0x02, 0x00};
    payload.insert(payload.end(), byteArray.begin(), byteArray.end());

    //SendDataFrame::getInstance().Send(0x218, 0x08, payload);
    SendDataFrame::getInstance().AddCanFrame(0x218, 0x08, payload);
}

/**
 * @brief Встановлює значення кутів енкодерів в градусах
 *
 * @param voltage_encoder_H Значення енкодеру по горизонталі (градуси)
 * @param voltage_encoder_V Значення енкодеру по вертикалі (градуси)
 *
 */
void ScriptCommands::SetAngleEncoder(float angle_encoder_H, float angle_encoder_V)
{
    SetAngleEncoder_H(angle_encoder_H);
    SetAngleEncoder_V(angle_encoder_V);

    // // Отримуємо сінглтон
    // SendDataFrame &sendDataFrame = SendDataFrame::getInstance();

    // std::vector<uint8_t> byteArray(4);

    // // Value H
    // std::memcpy(byteArray.data(), &angle_encoder_H, sizeof(float));
    // std::vector<uint8_t> payload_H = {0x00, 0x11, 0x02, 0x00};
    // payload_H.insert(payload_H.end(), byteArray.begin(), byteArray.end());
    // sendDataFrame.AddCanFrame(0x218, 0x08, payload_H);

    // // Value V
    // std::memcpy(byteArray.data(), &angle_encoder_V, sizeof(float));
    // std::vector<uint8_t> payload_V = {0x00, 0x21, 0x02, 0x00};
    // payload_V.insert(payload_V.end(), byteArray.begin(), byteArray.end());
    // sendDataFrame.AddCanFrame(0x218, 0x08, payload_V);

}

/**
 * @brief Встановлює значення кутів енкодерів в вольтах
 *
 * @param voltage_encoder_H Значення енкодеру по горизонталі (вольти)
 * @param voltage_encoder_V Значення енкодеру по вертикалі (вольти)
 *
 */
void ScriptCommands::SetVoltageEncoder(float voltage_encoder_H, float voltage_encoder_V)
{
    std::vector<uint8_t> payload;
    std::vector<uint8_t> byteArray(4);

    //передача координати X

    std::memcpy(byteArray.data(), &voltage_encoder_H, sizeof(float));

    payload = {0x00, 0x10, 0x02, 0x00};
    payload.insert(payload.end(), byteArray.begin(), byteArray.end());

    SendDataFrame::getInstance().AddCanFrame(0x118, 0x08, payload);

    //передача координати Y вгору
    std::memcpy(byteArray.data(), &voltage_encoder_V, sizeof(float));

    payload = {0x00, 0x20, 0x02, 0x00};
    payload.insert(payload.end(), byteArray.begin(), byteArray.end());

    SendDataFrame::getInstance().AddCanFrame(0x118, 0x08, payload);
    //SendDataFrame::getInstance().SendAllFrames();
}

/**
 * @brief Команда-запрос для того, щоб платформа надіслала режим роботи
 *
 * Надсилається постійно для контролю зміни режиму
 *
 */
void ScriptCommands::GetMode()
{
    std::vector<uint8_t> payload = {0x00, 0x00, 0x04, 0x01, 0x00, 0x00, 0x00, 0x00};
    SendDataFrame::getInstance().Send(0x118, 0x08, payload);
}

/**
 * @brief Встановлює режим платформи
 *
 * @param mode Значення режиму
 *
 */
void ScriptCommands::SetMode(ModePlatform mode)
{
    std::vector<uint8_t> payload
        = {0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, static_cast<uint8_t>(mode)};
    SendDataFrame::getInstance().Send(0x118, 0x08, payload);
}

/**
 * @brief Команда-запит поточного значення ЦАП в вольтах
 *
 * Надсилається постійно для контролю зміни напруги і виводу її у контрольне віконце
 *
 */
void ScriptCommands::AskValueDACHoriz()
{
    std::vector<uint8_t> payload = {0x00, 0x10, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00};
    SendDataFrame::getInstance().Send(0x218, 0x08, payload);
}

void ScriptCommands::AskValueDACVert()
{
    std::vector<uint8_t> payload = {0x00, 0x20, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00};
    SendDataFrame::getInstance().Send(0x218, 0x08, payload);
}

/**
 * @brief Встановлює потужність лазера
 *
 * @param value Значення потужності від 0 до 5. По замовчуванню станція працює на потужності 5
 *
 */
void ScriptCommands::SetLaserEnergy(uint8_t value)
{
    std::vector<uint8_t> payload = {0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, value};
    SendDataFrame::getInstance().Send(0x248, 0x08, payload);
}

/**
 * @brief Встановлює програмний нуль
 *
 * Функція обнуляє поточне положення станції. Тепер ці координати стануть нулем.
 *
 */
void ScriptCommands::SetProgrammZero()
{
    std::vector<uint8_t> payload
        = {0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    SendDataFrame::getInstance().Send(0x218, 0x08, payload);

    QThread::msleep(200); // Затримка 200 мс

    payload = {0x00, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    SendDataFrame::getInstance().Send(0x218, 0x08, payload);
}

/**
 * @brief Виконує zero set
 *
 * @param canal Канал: 0х10 - горизонтальний, 0х20 - вертикальний
 * @param command Команда: 0х2 - set, 0x3 - reset
 *
 */
void ScriptCommands::ZeroSet(uint8_t canal, uint8_t command)
{
    uint8_t id;

    // Power off
    id = ((uint8_t)(canal | 0x4));

    std::vector<uint8_t> payload
        = {0x00, id, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00};
    SendDataFrame::getInstance().Send(0x118, 0x08, payload);

    QThread::msleep(1000); // Затримка 1 c

    // Set 1
    id = ((uint8_t)(canal | command));
    payload = {0x00, id, 0x04, 0x00, 0x00, 0x00, 0x00, 0x01};
    SendDataFrame::getInstance().Send(0x118, 0x08, payload);

    QThread::msleep(500); // Затримка

    // Power on
    id = ((uint8_t)(canal | 0x4));

    payload = {0x00, id, 0x04, 0x00, 0x00, 0x00, 0x00, 0x01};
    SendDataFrame::getInstance().Send(0x118, 0x08, payload);

    // Delay 5 sec
    QThread::msleep(5000); // Затримка 5 сек

    // Set 0
    id = ((uint8_t)(canal | command));
    payload = {0x00, id, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00};
    SendDataFrame::getInstance().Send(0x118, 0x08, payload);

}


/**
 * @brief Передати координати точки для захоплення
 *
 * @param click_X Координата точки кліку по осі Х (пікселі)
 * @param click_Y Координата точки кліку по осі Y (пікселі)
 *
 */
void ScriptCommands::SetTrackingDot(uint16_t x, uint16_t y)
{
    std::vector<uint8_t> payload;

    payload = {0x00, 0x00, 0x0D, 0x00};

    // --- click_X (2 байти) ---
    payload.push_back(static_cast<uint8_t>(x & 0xFF));        // low byte
    payload.push_back(static_cast<uint8_t>((x >> 8) & 0xFF)); // high byte

    // --- click_Y (2 байти) ---
    payload.push_back(static_cast<uint8_t>(y & 0xFF));
    payload.push_back(static_cast<uint8_t>((y >> 8) & 0xFF));



    SendDataFrame::getInstance().AddCanFrame(0x198, 0x08, payload);


}

/**
 * @brief Скидання захоплення
 *
 *
 */
void ScriptCommands::ResetTracking()
{
    std::vector<uint8_t> payload;

    payload = {0x00, 0x01, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00 };

    SendDataFrame::getInstance().AddCanFrame(0x198, 0x08, payload);


}


