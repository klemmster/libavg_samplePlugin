#include "ProcessThread.h"

#include <base/Logger.h>
#include <base/IPlaybackEndListener.h>
#include <player/Player.h>
#include <player/AreaNode.h>
#include <player/TypeDefinition.h>

namespace avg
{

class MiniPluginNode: public AreaNode, IPlaybackEndListener
{
    public:
        MiniPluginNode(const ArgList& Args){
            AVG_LOG_INFO("Init Plugin");
            m_pCmdQueue = ProcessThread::CQueuePtr(new ProcessThread::CQueue);
            m_pWorkerThread = new boost::thread(ProcessThread(*m_pCmdQueue));
            Player::get()->registerPlaybackEndListener(this);
            Args.setMembers(this);
        }

        ~MiniPluginNode(){
            killThread();
            AVG_LOG_INFO("Deleted plugin");
        }

        static void registerType(){
            TypeDefinition def = TypeDefinition("PluginNode", "areanode",
                    ExportedObject::buildObject<MiniPluginNode>);
            const char * allowedParentNodeNames[] = {"avg", 0};
            avg::TypeRegistry::get()->registerType(def, allowedParentNodeNames);
        };

        virtual void onPlaybackEnd() {
            killThread();
        }
    protected:
        void killThread() {
            m_pCmdQueue->pushCmd(boost::bind(&ProcessThread::stop, _1));
            m_pWorkerThread->join();
            delete m_pWorkerThread;
        }

    private:
        boost::thread* m_pWorkerThread;

        ProcessThread::CQueuePtr m_pCmdQueue;
};
}
