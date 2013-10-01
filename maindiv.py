from libavg import avg

import libavg.app

g_Player = avg.Player.get()

class MyMainDiv(libavg.app.MainDiv):

    def onInit(self):
        super(MyMainDiv, self).onInit()
        g_Player.loadPlugin('miniPlugin')
        import miniPlugin
        self.node = miniPlugin.PluginNode()
