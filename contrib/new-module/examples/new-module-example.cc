#include "ns3/core-module.h"
// #include "ns3/tdma-helper.h"
#include "ns3/mobility-helper.h"
#include "ns3/net-device.h"
#include "ns3/node-container.h"
#include "ns3/applications-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/network-module.h"
/**
 * @file
 *
 * Explain here what the example does.
 */

using namespace ns3;

int
main(int argc, char* argv[])
{
    bool verbose = true;

    CommandLine cmd(__FILE__);
    cmd.AddValue("verbose", "Tell application to log if true", verbose);

    cmd.Parse(argc, argv);

    /* ... */
 // 创建 4 个节点
 NodeContainer nodes;
 nodes.Create (4);

 // 为节点设置静态位置（此处仅为示例，使用 ConstantPositionMobilityModel）
 MobilityHelper mobility;
 mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
 mobility.Install (nodes);

 // 对每个节点安装一个 TDMA MAC 实例
 for (uint32_t i = 0; i < nodes.GetN (); ++i)
   {
    //  Ptr<TdmaMac> tdmaMac = CreateObject<TdmaMac> ();
    //  tdmaMac->SetNodeId (i);
    //  tdmaMac->SetSlotDuration (MilliSeconds (20)); // 每个时隙20毫秒
    //  tdmaMac->Start ();

    //  // 模拟入队一个数据包（例如 100 字节）
    //  Ptr<Packet> packet = Create<Packet> (100);
    //  tdmaMac->Enqueue (packet);
   }

 Simulator::Stop (Seconds (1.0)); // 模拟1秒内运行

    Simulator::Run();
    Simulator::Destroy();
    return 0;
}
