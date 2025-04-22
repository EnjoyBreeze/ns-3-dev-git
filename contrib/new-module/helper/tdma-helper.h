#ifndef TDMA_HELPER_H
#define TDMA_HELPER_H

#include "ns3/tdma-mac.h"
#include "ns3/tdma-net-device.h"
#include "ns3/node-container.h"
#include "ns3/net-device-container.h"
#include "ns3/ptr.h"
#include "ns3/spectrum-channel.h"
#include "ns3/net-device.h"
#include "ns3/object.h"
namespace ns3
{
    class SpectrumChannel;
// Each class should be documented using Doxygen,
// and have an @ingroup new-module directive

/* ... */
class TdmaHelper
{
public:
  TdmaHelper ();
  ~TdmaHelper ();

  /// 设置物理层使用的信道
  void SetChannel (Ptr<SpectrumChannel> channel);
  
  /// 安装 TDMA 网络设备到给定节点容器，并返回设备容器
  NetDeviceContainer Install (NodeContainer nodes);

private:
  Ptr<SpectrumChannel> m_channel;
};

} // namespace ns3

#endif // NEW_MODULE_HELPER_H
