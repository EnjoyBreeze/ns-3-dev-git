#include "ns3/tdma-mac.h"
#include "ns3/tdma-net-device.h"
#include "ns3/spectrum-phy.h"
#include "ns3/node.h"
#include "ns3/log.h"
#include "ns3/tdma-helper.h"

namespace ns3
{

/* ... */
NS_LOG_COMPONENT_DEFINE ("TdmaHelper");

TdmaHelper::TdmaHelper ()
{
}

TdmaHelper::~TdmaHelper ()
{
}

void
TdmaHelper::SetChannel (Ptr<SpectrumChannel> channel)
{
  m_channel = channel;
}

NetDeviceContainer
TdmaHelper::Install (NodeContainer nodes)
{
  NetDeviceContainer devices;
  for (NodeContainer::Iterator it = nodes.Begin (); it != nodes.End (); ++it)
    {
      Ptr<Node> node = *it;
      
      // // 创建 SpectrumPhy 对象并关联信道
      // Ptr<SpectrumPhy> phy = CreateObject<SpectrumPhy> ();
      // phy->SetChannel (m_channel);

      // // 创建 TDMA MAC 对象，并绑定节点
      // Ptr<TdmaMac> tdmaMac = CreateObject<TdmaMac> ();
      // // tdmaMac->SetNode (node);
      // tdmaMac->Start ();

      // 创建 TDMA 网设备，并设置 PHY 与 TDMA MAC
      // Ptr<TdmaNetDevice> device = CreateObject<TdmaNetDevice> ();
      // device->SetPhy (phy);
      // device->SetTdmaMac (tdmaMac);
      // device->SetNode (node);
      
      // node->AddDevice (device);
      // devices.Add (device);
    }
  return devices;
}
} // namespace ns3
