/* TdmaNetDevice.cc */
#include "ns3/spectrum-phy.h"
#include "ns3/log.h"
#include "ns3/tdma-mac.h"
#include "ns3/node.h"
#include "ns3/tdma-net-device.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("TdmaNetDevice");
NS_OBJECT_ENSURE_REGISTERED (TdmaNetDevice);

TypeId
TdmaNetDevice::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::TdmaNetDevice")
    .SetParent<NetDevice> ()
    .SetGroupName ("Network");
    // .AddConstructor<TdmaNetDevice> ();
  return tid;
}

TdmaNetDevice::TdmaNetDevice ()
  : m_ifIndex (0)
{
  NS_LOG_FUNCTION (this);
}

TdmaNetDevice::~TdmaNetDevice ()
{
  NS_LOG_FUNCTION (this);
}

void
TdmaNetDevice::SetIfIndex (const uint32_t index)
{
  m_ifIndex = index;
}

uint32_t
TdmaNetDevice::GetIfIndex (void) const
{
  return m_ifIndex;
}

// Ptr<Channel>
// TdmaNetDevice::GetChannel (void) const
// {
//   if (m_phy)
//     {
//     //   return m_phy->GetChannel ();
//     }
//   return nullptr;
// }

void
TdmaNetDevice::SetAddress (Address address)
{
  // 此处可保存地址信息，示例中省略
}

Address
TdmaNetDevice::GetAddress (void) const
{
  return Address ();
}

bool
TdmaNetDevice::SetMtu (const uint16_t mtu)
{
  return true;
}

uint16_t
TdmaNetDevice::GetMtu (void) const
{
  return 1500;
}

bool
TdmaNetDevice::IsLinkUp (void) const
{
  return true;
}

void
TdmaNetDevice::AddLinkChangeCallback (Callback<void> callback)
{
  // 可注册链路状态变化的回调
}

bool
TdmaNetDevice::IsBroadcast (void) const
{
  return true;
}

Address
TdmaNetDevice::GetBroadcast (void) const
{
  return Address ();
}

bool
TdmaNetDevice::IsMulticast (void) const
{
  return true;
}

Address
TdmaNetDevice::GetMulticast (Ipv4Address multicastGroup) const
{
  return Address ();
}

bool
TdmaNetDevice::IsPointToPoint (void) const
{
  return false;
}

bool
TdmaNetDevice::IsBridge (void) const
{
  return false;
}

bool
TdmaNetDevice::Send (Ptr<Packet> packet, const Address& dest, uint16_t protocolNumber)
{
  NS_LOG_FUNCTION (this << packet << dest << protocolNumber);
  // 将数据包传递给 TDMA MAC 发送
  Ptr<TdmaMac> tdmaMac = DynamicCast<TdmaMac> (m_tdmaMac);
  if (tdmaMac)
    {
      tdmaMac->Enqueue (packet);
      return true;
    }
  return false;
}

bool
TdmaNetDevice::SendFrom (Ptr<Packet> packet, const Address& source, const Address& dest, uint16_t protocolNumber)
{
  return Send (packet, dest, protocolNumber);
}

Ptr<Node>
TdmaNetDevice::GetNode (void) const
{
  return m_node;
}

void
TdmaNetDevice::SetNode (Ptr<Node> node)
{
  m_node = node;
}

bool
TdmaNetDevice::NeedsArp (void) const
{
  return true;
}

void
TdmaNetDevice::SetReceiveCallback (NetDevice::ReceiveCallback cb)
{
  // 可实现数据包接收回调注册
}

void
TdmaNetDevice::SetPromiscReceiveCallback (PromiscReceiveCallback cb)
{
  // 可实现
}

bool
TdmaNetDevice::SupportsSendFrom (void) const
{
  return false;
}

void
TdmaNetDevice::SetPhy (Ptr<SpectrumPhy> phy)
{
  m_phy = phy;
}

void
TdmaNetDevice::SetTdmaMac (Ptr<Object> tdmaMac)
{
  m_tdmaMac = tdmaMac;
}

} // namespace ns3
