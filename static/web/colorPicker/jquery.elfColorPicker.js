/**
 * User: laichendong
 * Date: 13-8-29
 * Time: 下午1:51
 */
(function ($) {
    var _options = {};
    //插件方法
    $.fn.elfColorPicker = function (options) {
        _options = {};
        _options = $.extend({}, $.fn.elfColorPicker._options, options);
        return this.each(function () {
            var id = new Date().getTime();
            var trigger = $(this);
            trigger.data("cpUUID", "elfColorPicker_" + id);
            var valueForId = trigger.attr("value-for") ? trigger.attr("value-for") : 'elfColorValue_' + id;
            var valueFor = $("#" + valueForId);
            if (!valueFor || valueFor.length <= 0) {
                valueFor = $('<input type="hidden" id="' + valueForId + '" />');
                trigger.after(valueFor);
            }
            var extraColorLump;
            if (_options.extraColorLump) {
                var extraColorLumpId = trigger.attr("visaul-for") ? trigger.attr("visaul-for") : 'elfColorLump_' + id;
                extraColorLump = $("#" + extraColorLumpId);
                if (!extraColorLump || extraColorLump.length <= 0) {
                    extraColorLump = $('<span class="elf_color_lump" id="' + extraColorLumpId + '" >&nbsp;</span>');
                    trigger.after(extraColorLump);
                }
            }
            var elfColorPickerObj = build(trigger);

            // 事件绑定
            eventHandle(trigger, elfColorPickerObj, valueFor, extraColorLump);
        });
    };
    //插件默认选项
    $.fn.elfColorPicker._options = {
        picked: function (c) {
        }, // 颜色选中后的回调函数
        beforeOpen: function () {
        }, // 打开前回调
        opened: function () {
        }, // 控件打开时的回调函数
        beforeClose: function () {
        }, // 关闭前回调
        closed: function () {
        }, // 关闭后回调
        triggerType: "normal", // [normal|button] 触发器类型，普通和按钮
        extraColorLump: false // 是否有显示额外的色块
    };
    //构建html结构
    function build(trigger) {
        var cpUUID = trigger.data("cpUUID");
        var elfColorPickerObj = $(
            '<div class="elfColorPicker_box" id="' + cpUUID + '">' +
                '<ul class="clr_body clearfix"></ul>' +
                '<div class="clr_button_bar clearfix">' +
                '<a class="f_l clr_clear_btn clr_btn" href="javascript:void(0);">清空</a>' +
                '<a class="f_r clr_cancel_btn clr_btn" href="javascript:void(0);">关闭</a>' +
                '</div>' +
                '</div>').appendTo("body");
        for (var r = 0; r < 256; r += 51) {
            for (var g = 0; g < 256; g += 51) {
                for (var b = 0; b < 256; b += 51) {
                    var c = (r == 0 ? "00" : r.toString(16)) + (g == 0 ? "00" : g.toString(16)) + (b == 0 ? "00" : b.toString(16));
                    elfColorPickerObj.find(".clr_body").append('<li class="f_l clr_item" style="background: #' + c + '" c=' + c + '></li>');
                }
            }
        }
        return elfColorPickerObj;
    }


    // 交互事件处理
    function eventHandle(trigger, elfColorPickerObj, valueFor, extraColorLump) {
        trigger.click(function () {
            /*
             * trigger click 显示隐藏控件
             */
            if (_options.triggerType == "button" && trigger.attr("disabled")) {
                return;
            }
            toggle(trigger, elfColorPickerObj, valueFor, extraColorLump);
        });
        elfColorPickerObj
            .delegate("li.clr_item", "mouseenter",function () {
                /*
                 * 鼠标进入某一颜色  预览选中后的效果
                 */
                previewData($(this).attr("c"), trigger, valueFor, extraColorLump);
            }).delegate("li.clr_item", "click",function () {
                /*
                 * 鼠标点击某一颜色  选中该颜色
                 */
                setData($(this).attr("c"), trigger, valueFor, extraColorLump);
                hide(trigger, elfColorPickerObj, valueFor, extraColorLump, false);
                _options.picked($(this).attr("c"));
            }).delegate("ul.clr_body", "mouseleave",function () {
                /*
                 * 鼠标移出颜色选择区  恢复之前的选中状态
                 */
                resetData(trigger, valueFor, extraColorLump);
            }).delegate(".clr_cancel_btn", "click",function () {
                /*
                 * 点击关闭按钮，关闭自己
                 */
                hide(trigger, elfColorPickerObj, valueFor, extraColorLump, true);
            }).delegate(".clr_clear_btn", "click", function () {
                /*
                 * 点击按钮按钮，清空数据并关闭自己
                 */
                clearData(trigger, valueFor, extraColorLump);
                hide(trigger, elfColorPickerObj, valueFor, extraColorLump, true);
            });

    }

    // 显示/隐藏控件
    function toggle(trigger, elfColorPickerObj, valueFor, extraColorLump) {
        if (elfColorPickerObj.data("isShow")) {
            hide(trigger, elfColorPickerObj, valueFor, extraColorLump, true);
        } else {
            show(trigger, elfColorPickerObj, valueFor);
        }
    }

    //显示控件
    function show(trigger, elfColorPickerObj, valueFor) {
        _options.beforeOpen();
        trigger.data("origColor", trigger.css("background-color"));
        valueFor.data("origColor", valueFor.val());
        elfColorPickerObj.css({
            position: "absolute",
            left: trigger.offset().left,
            top: trigger.offset().top + trigger.outerHeight()
        }).show(200, function () {
                $(this).data("isShow", true);
                $.fn.elfColorPicker._options.opened();
            });
    }

    //影藏控件
    function hide(trigger, elfColorPickerObj, valueFor, extraColorLump, reset) {
        _options.beforeClose();
        if (reset) {
            resetData(trigger, valueFor, extraColorLump);
        }
        elfColorPickerObj.hide(0, function () {
            $(this).data("isShow", false);
            _options.closed();
        });
    }

    function previewData(c, trigger, valueFor, extraColorLump) {
        if (_options.triggerType == "normal") {
            trigger.css({"background-color": "#" + c});
        }
        valueFor.val("#" + c);
        if (_options.extraColorLump) {
            extraColorLump.css({"background-color": "#" + c});
        }
    }

    function resetData(trigger, valueFor, extraColorLump) {
        if (_options.triggerType == "normal") {
            trigger.css({"background-color": trigger.data("origColor")});
        }
        valueFor.val(valueFor.data("origColor"));
        if (_options.extraColorLump) {
            extraColorLump.css({"background-color": extraColorLump.data("origColor")});
        }
    }

    function setData(c, trigger, valueFor, extraColorLump) {
        previewData(c, trigger, valueFor, extraColorLump);
        trigger.data("origColor", trigger.css("background-color"));
        valueFor.data("origColor", valueFor.val());
        if (_options.extraColorLump) {
            extraColorLump.data("origColor", extraColorLump.css("background-color"));
        }

    }

    function clearData(trigger, valueFor, extraColorLump) {
        if (_options.triggerType == "normal") {
            trigger.css({"background-color": "#ffffff"});
        }
        valueFor.val("");
        if (_options.extraColorLump) {
            extraColorLump.css({"background-color": "#ffffff"});
        }
        trigger.data("origColor", trigger.css("background-color"));
        valueFor.data("origColor", valueFor.val());
        if (_options.extraColorLump) {
            extraColorLump.data("origColor", extraColorLump.css("background-color"));
        }
    }

})(jQuery)