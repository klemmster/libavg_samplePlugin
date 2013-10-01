#include <wrapper/WrapHelper.h>
#include <wrapper/raw_constructor.hpp>

#include "MinimalPluginNode.h"

using namespace boost::python;

char PluginNode[] = "PluginNode";

BOOST_PYTHON_MODULE(miniPlugin)
{
    class_<avg::MiniPluginNode,
                boost::shared_ptr<avg::MiniPluginNode>, boost::noncopyable>
                ("PluginNode", no_init)
                .def("__init__", raw_constructor(createNode<PluginNode>))
                ;
};

AVG_PLUGIN_API void registerPlugin()
{
    initminiPlugin();
    object miniPluginModule(handle<>(PyImport_ImportModule("miniPlugin")));
    avg::MiniPluginNode::registerType();
};
