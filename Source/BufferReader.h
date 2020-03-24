#pragma once

namespace spectrum
{
class BufferReader : public Component
{
private:
public:
    BufferReader();
    ~BufferReader() override;

    void onUpdate() override;
};

} // namespace spectrum