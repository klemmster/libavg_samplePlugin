#!/usr/bin/env python
# -*- coding: utf-8 -*-

from libavg import avg, AVGApp

from alib import app

import logging

log = logging.getLogger(__name__)
log.addHandler(logging.StreamHandler())

g_Player = avg.Player.get()

class TestPlugin(AVGApp):

    def init(self):
        g_Player.loadPlugin('miniPlugin')
        self.node = miniPlugin.PluginNode()
        g_Player.setInterval(10, self._log)
        #g_Player.setTimeout(20000, self._crash)

    def _log(self):
        log.warning("From App")

    def _crash(self):
        del self.node
        self.node = None
        raise Exception("Crashing Plugin")

if __name__ == '__main__':
    TestPlugin.start(resolution=(800, 480))
